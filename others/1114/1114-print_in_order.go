package main

import (
	"sync"
)

type Foo struct {
	second chan bool
	third  chan bool
}

func NewFoo() *Foo {
	return &Foo{
		second: make(chan bool),
		third:  make(chan bool),
	}
}

func (f *Foo) First(printFirst func(), wg *sync.WaitGroup) {
	defer wg.Done() 
	printFirst()
	f.second <- true
}

func (f *Foo) Second(printSecond func(), wg *sync.WaitGroup) {
	defer wg.Done()
	<-f.second
	printSecond()
	f.third <- true
}

func (f *Foo) Third(printThird func(), wg *sync.WaitGroup) {
	defer wg.Done()
	<-f.third
	printThird()
}

func main() {
	foo := NewFoo()
	var wg sync.WaitGroup

	p1 := func() { println("First") }
	p2 := func() { println("Second") }
	p3 := func() { println("Third") }

	wg.Add(3)

	go foo.Third(p3, &wg)
	go foo.Second(p2, &wg)
	go foo.First(p1, &wg)

	wg.Wait()
}