/*
 * @lc app=leetcode id=62 lang=cpp
 *
 * [62] Unique Paths
 */

// @lc code=start

#include <vector>
using namespace std;

class Solution {
   public:
    int uniquePaths(int m, int n) {
        // Idea: use dynamic programming
        // dp[i][j] = number of ways to achieve at i,j
        // question dp[m-1][n-1]
        // formula: dp[i][j] = dp[i-1][j] + dp[i][j-1]
        vector<vector<int>> dp(n, vector<int>(m, 0));
        dp[0][0] = 1;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                // if (i == 0 && j == 0) {
                //     dp[0][0] = 1;
                //     continue;
                // }

                if (i > 0) dp[i][j] += dp[i - 1][j];  // Add paths from the top
                if (j > 0) dp[i][j] += dp[i][j - 1];  // Add paths from the left
            }
        }
        return dp[n - 1][m - 1];
    }
};
// @lc code=end
