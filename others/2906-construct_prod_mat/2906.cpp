#include <iostream>
#include <vector>


class Solution {
public:
    std::vector<std::vector<int>> constructProductMatrix(std::vector<std::vector<int>>& grid) {
        int mod = 12345;
        int n = grid.size(), m = grid[0].size();

        std::vector<std::vector<int>> res (n, std::vector<int>(m));
        long long pre = 1, suf = 1;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                res[i][j] = pre;
                pre = (pre*grid[i][j]) % mod;
            }
        }

        for (int i = n - 1; i >= 0; --i) {
            for (int j = m - 1; j >= 0; j--) {
                res[i][j] = (res[i][j] * suf) % mod;
                suf = (suf * grid[i][j]) % mod;
            }
        }
        return res;

    }
};


struct TestCase {
    std::vector<std::vector<int>> in;
    std::vector<std::vector<int>> exp;
};

void printMatrix(const std::vector<std::vector<int>>& mat) {
    std::cout << "[";
    for (int i = 0; i < mat.size(); ++i) {
        std::cout << "[";
        for (int j = 0; j < mat[i].size(); ++j) {
            std::cout << mat[i][j] << (j == mat[i].size() - 1 ? "" : ",");
        }
        std::cout << "]" << (i == mat.size() - 1 ? "" : ",");
    }
    std::cout << "]" << std::endl;
}

int main() {
    Solution soln;
    std::vector<TestCase> tests { {{{1,2},{3,4}},{{24,2},{8,6}}},{{{12345},{2},{1}},{{2},{0},{0}}}};
    for (auto& t : tests) {
        printMatrix(soln.constructProductMatrix(t.in));
    }
    return 0;
};