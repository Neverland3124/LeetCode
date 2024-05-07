/*
 * @lc app=leetcode id=26 lang=java
 *
 * [26] Remove Duplicates from Sorted Array
 */

// @lc code=start

// two pointer
class Solution {
    public int removeDuplicates(int[] nums) {
        if (nums.length == 0) 
            return 0;
        
        int slow = 0, fast = 0;
        while (fast < nums.length) {
            if (nums[fast] != nums[slow]) {
                slow++;
                nums[slow] = nums[fast];
            }
            fast++;
        }
        // index + 1 is the length
        return slow + 1;
    }
}
// @lc code=end

