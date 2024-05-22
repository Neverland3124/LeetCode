/*
 * @lc app=leetcode id=63 lang=cpp
 *
 * [63] Unique Paths II
 */

// @lc code=start

#include <vector>
using namespace std;

class Solution {
   public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));

        if (obstacleGrid[0][0] == 1) {
            // If the start is an obstacle, there are no paths.
            return 0;
        }

        dp[0][0] = 1;
        // a way of optimizer is go through 0j and i0 beforehand, but it's not
        // nesscessary

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                // if (i == 0 && j == 0) {
                //     dp[0][0] = 1;
                //     continue;
                // }

                // need to handle the obstacle now, if we have the obstacle,
                // mark the way 0
                if (obstacleGrid[i][j] == 1) {
                    // case of current is obstacle
                    dp[i][j] = 0;
                } else {
                    if (i > 0) dp[i][j] += dp[i - 1][j];  // Add paths from the top
                    if (j > 0) dp[i][j] += dp[i][j - 1];  // Add paths from the left
                }
            }
        }
        return dp[n - 1][m - 1];
    }
};
// @lc code=end
