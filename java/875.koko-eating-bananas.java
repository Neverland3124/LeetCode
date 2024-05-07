/*
 * @lc app=leetcode id=875 lang=java
 *
 * [875] Koko Eating Bananas
 */

// @lc code=start
class Solution {
    public int minEatingSpeed(int[] piles, int h) {
        int left = 1;
        int right = 0;
        for (int i : piles)
            right = Math.max(i, right);

        while (left <= right) {
            int mid = (left + right) / 2;
            if (canEatInTime(piles, mid, h))
                right = mid - 1;
            else
                left = mid + 1;
        }
        return left;
    }

    public boolean canEatInTime(int piles[], int k, int h) {
        int hours = 0;
        for (int pile : piles) {
            // need to be double since float is not big enough
            double div = pile / k;
            hours += div;
            if (pile % k != 0)
                hours++;
        }
        return hours <= h;
    }
}
// @lc code=end
