#include <iostream>
#include <vector>
#include <array>
#include <algorithm>

class Solution {
public:
    static std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
        int n = nums.size();
        std::vector<std::vector<int>> res;

        // Sort to allow skipping past integers of the same values
        std::sort(nums.begin(),nums.end());

        // We maintain the first pointer i starting from the leftmost number
        for (int i = 0; i < n - 2; ++i) {
            if (i >= 1 && nums[i-1]==nums[i]) continue;  // Skip duplicate integers for i

            // Now we introduce two more pointers j, k
            int j = i + 1, k = n - 1;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k]; // Calculate the sum of nums indexed at i, j, k
                if (sum == 0) {
                    res.push_back({nums[i],nums[j],nums[k]});
                    while (j<k && nums[j] == nums[j+1]) j++; // More duplicate checking
                    while (j<k && nums[k] == nums[k-1]) k--;
                    j++, k--;
                }
                else if (sum < 0) ++j;
                else if (sum > 0 ) --k;
            }
        }
        return res;
    }
};

int main() {
    std::vector<std::vector<int>> tests = {{-1, 0, 1, 2, -1, -4}, {0, 1, 1}, {0, 0, 0}};

    for (auto& t : tests) {
        std::vector<std::vector<int>> current_res = Solution::threeSum(t);
        std::cout << "["; 
        for (size_t i = 0; i < current_res.size(); ++i) {
            std::cout << "[";
            for (size_t k = 0; k < current_res[i].size(); ++k) {
                std::cout << current_res[i][k] << (k == current_res[i].size() - 1 ? "" : ",");
            }
            std::cout << "]" << (i == current_res.size() - 1 ? "" : ", ");
        }
        std::cout << "]" << std::endl; 
    }

    return 0;
}