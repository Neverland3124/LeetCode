/*
 * @lc app=leetcode id=704 lang=cpp
 *
 * [704] Binary Search
 */

// @lc code=start

#include <vector>
using namespace std;

class Solution {
   public:
    int search(vector<int>& nums, int target) {
        // Use binary search to find the target
        int left = 0;
        int right = nums.size() - 1;
        int result = -1;

        while (left <= right) {
            // If even return the left one
            int mid = (left + right) / 2;
            if (nums[mid] == target) {
                result = mid;
                break;
            }

            if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return result;
    }
};
// @lc code=end
