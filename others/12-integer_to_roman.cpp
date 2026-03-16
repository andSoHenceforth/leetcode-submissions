#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        const vector<pair<string, int>> roman_values = {
            {"M", 1000},
            {"CM", 900},
            {"D", 500},
            {"CD", 400},
            {"C", 100},
            {"XC", 90},
            {"L", 50},
            {"XL", 40},
            {"X", 10},
            {"IX", 9},
            {"V", 5},
            {"IV", 4},
            {"I", 1},
        };

        string res;

        for (const auto& [str, val] : roman_values) {
            if (num == 0) break;
            while (val <= num) {
                num -= val;
                res += str;
            }
        }
        return res;
    }
};


int main() {
    Solution sol;
    cout << sol.intToRoman(12345);
}