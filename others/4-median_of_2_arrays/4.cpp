#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> combined;

        for (int num : nums1) {
            combined.push_back(num);
        }

        for (int num : nums2) {
            combined.push_back(num);
        }

        sort(combined.begin(), combined.end());

        int n = combined.size();

        return (n % 2) ? combined[n/2] : (combined[n/2-1]+combined[n/2]) / 2.0;
        
    }
};