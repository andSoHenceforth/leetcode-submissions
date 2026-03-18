#include <iostream>
#include <cmath>
using namespace std;

// Simply binary search approach

class Solution {
public:
    int mySqrt(int x) {
        if (x==0) return 0;

        int lo = 1, hi = x;
        
        while (lo <= hi) {
            long long mi = lo + (hi - lo)/2;
            if (mi * mi <= x) {
                lo = mi + 1;
            }
            else {
                hi = mi - 1;
            }
        }
        return hi;
    }
};

int main() {
    Solution soln;
    for (int i = 0; i <= 1000000; ++i) {
        int res = soln.mySqrt(i);
        if (res != (int)pow(i, 0.5)) {
            cout << "Error at " << i << "with output" << res;
        }
    }
    return 0;
}