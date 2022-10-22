/*
 * @lc app=leetcode id=63 lang=java
 *
 * [63] Unique Paths II
 */

// @lc code=start
// my solution
// class Solution {
//     public int uniquePathsWithObstacles(int[][] obstacleGrid) {
//         int m = obstacleGrid.length;
//         int n = obstacleGrid[0].length;
//         if (m == 0 || n == 0)
//             return 0;
//         int[][] mem = new int[m][n];
//         for (int i = 0; i < m; i++) { // init
//             for (int j = 0; j < n; ++j) {
//                 mem[i][j] = -2;
//             }
//         }
//         return numPaths(m - 1, n - 1, mem, obstacleGrid);
//     }

//     private int numPaths(int i, int j, int[][] mem, int[][] obstacleGrid) {
//         if (obstacleGrid[i][j] == 1){
//             // this grid cannot pass
//             mem[i][j] = 0;
//             return 0;
//         }
//         // since we can have obstacle which lead 0, i ==0 and j == 0 need to consider differently
//         if(i == 0 && j == 0){
//             return 1;
//         }
//         if (i == 0){
//             return numPaths(i, j - 1, mem, obstacleGrid);
//         }
//         if (j == 0){
//             return numPaths(i - 1, j, mem, obstacleGrid);
//         }
//         // first time meet, calculate it
//         if (mem[i - 1][j] == -2)
//             mem[i - 1][j] = numPaths(i - 1, j, mem, obstacleGrid);
//         // first time meet, calculate it
//         if (mem[i][j - 1] == -2)
//             mem[i][j - 1] = numPaths(i, j - 1, mem, obstacleGrid);
//         return mem[i - 1][j] + mem[i][j - 1];
//     }
// }

// forward dp
// class Solution {
//     int dp[][];
//     int m, n;
//     int[][] obstacle;

//     public int uniquePathsWithObstacles(int[][] obstacleGrid) {
//         m = obstacleGrid.length;
//         n = obstacleGrid[0].length;
//         obstacle = obstacleGrid;
//         dp = new int[m][n];
//         for (int i = 0; i < m; i++) { // init
//             for (int j = 0; j < n; j++) {
//                 dp[i][j] = -1;
//             }
//         }
//         return recurse(0, 0);
//     }

//     // memo dp
//     public int recurse(int i, int j) {
//         // go over the end or reach obstacle
//         if (i == m || j == n || obstacle[i][j] == 1)
//             return 0;
//         // dp[i][j] already stored
//         if (dp[i][j] != -1)
//             return dp[i][j]; // return the already computed value for cell (i, j)
//         // reach last one
//         if (m - 1 == i && j == n - 1){
//             dp[i][j] = 1;
//             return dp[i][j];
//         }
//         // reversely
//         dp[i][j] = recurse(i, j + 1) + recurse(i + 1, j); // store value for cell (i, j)
//         return dp[i][j];
//     }
// }

// iterative
class Solution {
    public int uniquePathsWithObstacles(int[][] obstacleGrid) {
        int m = obstacleGrid.length;
        int n = obstacleGrid[0].length;
        int[][] dp = new int[m][n];
        for (int i = 0; i < m; i++) {
            if (obstacleGrid[i][0] == 1) {
                // break because no possible to run in [i][0]
                break;
            } else {
                dp[i][0] = 1;
            }
        }
        for (int i = 0; i < n; i++) {
            if (obstacleGrid[0][i] == 1) {
                // break because no possible to run in [0][i]
                break;
            } else {
                dp[0][i] = 1;
            }
        }
        // for loop to dp
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; ++j) {
                if (obstacleGrid[i][j] != 1) {
                    // upper + left = current value
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                }
            }
        }
        return dp[m - 1][n - 1];
    }
}
// class Solution {
//     public int uniquePathsWithObstacles(int[][] obstacleGrid) {
//         int m = obstacleGrid.length;
//         int n = obstacleGrid[0].length;
//         int[][] cache = new int[m][n];
//         for (int i = 0; i < n; i++) {
//             if (obstacleGrid[0][i] != 1) {
//                 cache[0][i] = 1;
//             } else {
//                 break;
//             }
//         }
//         for (int i = 0; i < m; i++) {
//             if (obstacleGrid[i][0] != 1) {
//                 cache[i][0] = 1;
//             } else {
//                 break;
//             }
//         }
//         for (int row = 1; row < m; row++) {
//             for (int col = 1; col < n; col++) {
//                 if (obstacleGrid[row][col] != 1) {
//                     cache[row][col] = cache[row - 1][col] + cache[row][col - 1];
//                 }
//             }
//         }
//         return cache[m - 1][n - 1];
//     }
// }


// dfs - time exceed
// class Solution {
//     int count = 0;

//     public int uniquePathsWithObstacles(int[][] grid) {
//         dfs(grid, 0, 0);
//         return count;
//     }

//     public void dfs(int grid[][], int i, int j) {
//         if (i < 0 || j < 0 || i >= grid.length || j >= grid[0].length || grid[i][j] == 1)
//             return;
//         if (i == grid.length - 1 && j == grid[0].length - 1) {
//             count++;
//             return;
//         }

//         dfs(grid, i + 1, j);
//         dfs(grid, i, j + 1);
//     }
// }
// @lc code=end
