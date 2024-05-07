/*
 * @lc app=leetcode id=300 lang=java
 *
 * [300] Longest Increasing Subsequence
 */

// @lc code=start
// patient sort way
// size is the pile of cards, new smaller bigger cards in right side
// class Solution {
//     public int lengthOfLIS(int[] nums) {
//         int[] tails = new int[nums.length];
//         // tails = [0, 0]
//         int size = 0;
//         // nums = [10,9,2,5,3,7,101,18]
//         for (int x : nums) {
//             int i = 0, j = size;
//             while (i != j) {
//                 // i = 0, size = 1 = j
//                 int m = (i + j) / 2;
//                 if (tails[m] < x)
//                     // i change when x >= tails[m]
//                     i = m + 1;
//                 else
//                     j = m;
//             }
//             tails[i] = x;
//             // tails[0] = 10 / 9 / 2 
//             // tails[1] = 
//             if (i == size)
//                 ++size;
//         }
//         return size;
//     }
// }
// dp
class Solution {
    public static int lengthOfLIS(int[] nums) {
        int[] dp = new int[nums.length];
        // init
        Arrays.fill(dp, 1);
        int ans = 1;
        for (int i = 1; i < dp.length; i++) {
            // check everything before you
            for (int j = 0; j < i; j++) {
                // if you are big than it
                if (nums[i] > nums[j]) {
                    // your biggest or it + 1
                    dp[i] = Math.max(dp[i], dp[j] + 1);
                }
                // result update
                ans = Math.max(ans, dp[i]);
            }
        }
        return ans;
    }
}
// @lc code=end
