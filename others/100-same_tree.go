package main

import "fmt"

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func isSameTree(p *TreeNode, q *TreeNode) bool {
	if p == nil && q == nil {
		return true
	}
	if p == nil || q == nil || p.Val != q.Val {
		return false
	}
	return isSameTree(p.Left, q.Left) && isSameTree(p.Right, q.Right)
}

func main() {
	tree1 := &TreeNode{Val: 1, Left: &TreeNode{Val: 2}}
	tree2 := &TreeNode{Val: 1, Left: &TreeNode{Val: 2}}
	result := isSameTree(tree1, tree2)
	fmt.Print(result)
}