/*
 * @lc app=leetcode id=33 lang=cpp
 *
 * [33] Search in Rotated Sorted Array
 */

// @lc code=start

#include <vector>
using namespace std;

class Solution {
   public:
    int search(vector<int>& nums, int target) {
        // Idea: example nums: [4,5,6,7,0,1,2], we will need to find the target
        // in O(logn) time, so we need a modified version of binary search
        // one part of the binary search will be ordered and sorted, if the
        // target is between the ordered part, just ordinary binary search if
        // the target is on the other part, then we will have case of left.val
        // bigger than right.val we partition the array until
        // Note: this effectively use the property that one of the left and
        // right part of the array is sorted in rotated sorted array

        // This is the position of the binary search
        int left = 0;
        int right = nums.size() - 1;
        int result = -1;

        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] == target) {
                result = mid;
                break;
            }
            
            if (nums[left] <= nums[mid]) {
                // means the left part is sorted
                if (nums[left] <= target && target <= nums[mid]) {
                    // case 1: target on the left part
                    right = mid - 1;
                } else {
                    // case 2: target on the right part
                    left = mid + 1;
                }
            } else {
                // means the left part is not sorted
                // i.e. right part is sorted
                if (nums[mid] <= target && target <= nums[right]) {
                    // case 1: target on the right part
                    left = mid + 1;
                } else {
                    // case 2: target on the left part
                    right = mid - 1;
                }
            }
        }

        return result;
    }
};
// @lc code=end
