#include <iostream>
#include <algorithm>
#include <bitset>
using namespace std;

class Solution {
public:
    int binaryGap(int n) {
        int res, cur = 0;
        bool first_found = false;

        while (n>0) {res = max(res,cur);
            int bit = n%2;
            if (bit == 1) {
                if (first_found) {
                    res = max(cur,res);
                }
                first_found = true;
                cur = 1;

            } else {
                if (first_found) cur++;
            }
            n /= 2;

        }
        return res;
    }
};

int main() {
    Solution sol;
    cout << "tests" << endl;
    for (int i = 1; i <=30;i++) {
        int res = sol.binaryGap(i);
        cout << "n = " << i << " (" << bitset<5>(i) << ") with gap " << res << endl;
    }
    return 0;

}