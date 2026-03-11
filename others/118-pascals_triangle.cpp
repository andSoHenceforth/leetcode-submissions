#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        for (int i = 0; i < numRows; i++) {
            vector<int> row;
            int val = 1;
            for (int j = 0; j <=i; j++) {
                row.push_back(val);
                val = val * (i-j)/(j+1);
            }
            res.push_back(row);
        }
        return res;
    }
};

int main() {
    Solution soln;
    int rows = 11;
    vector<vector<int>> result = soln.generate(rows);

    for (const auto& row: result) {
        for (int x:row) {
            cout << x << " ";
        }
        cout << endl;
    }
}