/*
 * @lc app=leetcode id=162 lang=java
 *
 * [162] Find Peak Element
 */

// @lc code=start
class Solution {
    public int findPeakElement(int[] nums) {
        if (nums.length == 1)
            return 0; // single element

        int n = nums.length;

        // check if 0th/n-1th index is the peak element
        if (nums[0] > nums[1])
            return 0;
        if (nums[n - 1] > nums[n - 2])
            return n - 1;

        // search in the remaining array
        int start = 1;
        int end = n - 2;

        // binary search
        while (start <= end) {
            int mid = (start + end) / 2;
            // if mid is higher than left and right
            if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1])
                return mid;
            // if mid is smaller than left, end = left
            else if (nums[mid] < nums[mid - 1])
                end = mid - 1;
            // if mid is bigger than left, end = right
            else if (nums[mid] < nums[mid + 1])
                start = mid + 1;
        }
        return -1; // dummy return statement
    }
}
// @lc code=end
