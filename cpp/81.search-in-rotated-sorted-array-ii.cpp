/*
 * @lc app=leetcode id=81 lang=cpp
 *
 * [81] Search in Rotated Sorted Array II
 */

// @lc code=start

#include <vector>
using namespace std;

class Solution {
   public:
    bool search(vector<int>& nums, int target) {
        // Question: why the distinct version not working for the non-distinct version?
        // [1,0,1,1,1] try to find 0, expected: true, output: false with original method

        // Solution: Need to handle the special case of head = mid = tail
        //  in this case, both head and tail cannot be the target, so we can safely move head and
        //  tail to the next position
        int left = 0;
        int right = nums.size() - 1;
        bool result = false;

        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] == target) {
                result = true;
                break;
            }

            if (nums[left] == nums[mid] && nums[mid] == nums[right]) {
                // special case
                left++;
                right--;
                continue;
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
