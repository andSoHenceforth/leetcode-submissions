#include <iostream>
#include <vector>


class Solution {
    public:
    static std::string convert(std::string s, int numRows) {
        if (numRows == 1) return s;
        std::string res = "";
        int n = s.length(), cycle = 2 * numRows - 2;
        for (int i = 0; i < numRows; ++i) {
            int j = i;
            while (j < n) {
                res += s[j];
                int toSkip = cycle - 2 *i;
                if (i == 0 || i == numRows - 1) {
                    j += cycle;
                } else {
                    if (j + toSkip < n) {
                        res += s[j + toSkip];
                    }
                    j += cycle; 
                }
            }
        }
        return res;
    }
};

struct TestCase {
    std::string input;
    int numRows;
    std::string expected;
};


int main() {
    std::vector<TestCase> tests = {
    {"PAYPALISHIRING", 3, "PAHNAPLSIIGYIR"},
    {"PAYPALISHIRING", 4, "PINALSIGYAHRPI"},
    {"A", 1, "A"}
};
    Solution soln;
    std::cout << "-------------------------------------------\n";
    for (auto& test : tests) {
        std::cout << "s = \"" << test.input << "\", numRows = " << test.numRows << std::endl;
        std::string res = soln.convert(test.input, test.numRows);
        std::cout << "ans: \"" << res << "\"" << std::endl;
        std::cout << (res == test.expected ? "matches " : "does not match ") << "expected output \"" << test.expected << "\"" << std::endl;
        std::cout << "-------------------------------------------\n";
    }
    return 0;
};