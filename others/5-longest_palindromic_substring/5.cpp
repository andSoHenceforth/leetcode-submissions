#include <iostream>
#include <vector>

class Solution {
public:
    static std::string longestPalindrome(std::string s) {
        int n = s.length();

        if (n < 2) return s;

        int start = 0, max_len = 0;

        auto expand = [&](int l,int r) {
            while (l>=0&& r<s.length() && s[l] == s[r]) {
                l--;
                r++;
            };
            int curr_len = r - l - 1;
            if (curr_len > max_len) {
                start = ++l;
                max_len = curr_len;
            }
        };
        for (int i = 0; i<s.length();i++) {
            expand(i,i);
            expand(i,i+1);
        }
        return s.substr(start, max_len);
    }
};

int main() {
    std::vector<std::string> tests = {"abba", "nope", "aracecarzzz"};
    std::vector<std::string> res;
    for (const std::string& s: tests) {
        res.push_back(Solution::longestPalindrome(s));
    }
    for (std::vector<std::string>::iterator it = res.begin(); it!= res.end(); ++it) {
        std::cout << *it << '\n'; 
    }
    return 0;
}


