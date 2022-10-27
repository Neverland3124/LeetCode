/*
 * @lc app=leetcode id=1283 lang=java
 *
 * [1283] Find the Smallest Divisor Given a Threshold
 */

// @lc code=start
class Solution {
    public int smallestDivisor(int[] nums, int h) {
        int left = 1;
        int right = 0;
        for (int n : nums)
            right = Math.max(right, n);

        while (left <= right) {
            int mid = (left + right) / 2;
            if (canDivide(nums, mid, h))
                right = mid - 1;
            else
                left = mid + 1;
        }
        return left;
    }

    public boolean canDivide(int nums[], int k, int h) {
        int hours = 0;
        for (int num : nums) {
            // need to be double since float is not big enough
            double div = num / k;
            hours += div;
            if (num % k != 0)
                hours++;
        }
        return hours <= h;
    }
}
// @lc code=end
