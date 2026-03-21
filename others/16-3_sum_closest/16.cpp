#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <cmath>
#include <limits.h>
#include <format>

class Solution {
public:
    static int threeSumClosest(std::vector<int>& nums, int target) {
        int n = nums.size();
        long res = INT_MAX;

        // Sort to allow skipping past integers of the same values
        std::sort(nums.begin(),nums.end());
        // We maintain the first pointer i starting from the leftmost number
        for (int i = 0; i < n - 2; ++i) {
            if (i >= 1 && nums[i-1]==nums[i]) continue;  // Skip duplicate integers for i

            // Now we introduce two more pointers j, k
            int j = i + 1, k = n - 1;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k]; // Calculate the sum of nums indexed at i, j, k
                if (sum == target) return sum;
                if (std::abs(target - sum) < std::abs(target - res)) {
                    res = sum;
                }
                if (sum < target) j++;
                else k--;


            }
        }
        return res;
    }
};

struct TestCase {
    std::vector<int> nums;
    int target;
};

int main() {
    std::vector<TestCase> tests = {{{-1,2,1,-4},1}, {{0,0,0},1}};

    for (auto& t : tests) {
        int current_res = Solution::threeSumClosest(t.nums, t.target);
        std::cout << current_res << std::endl;
    }

    return 0;
}