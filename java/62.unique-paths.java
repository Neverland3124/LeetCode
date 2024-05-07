/*
 * @lc app=leetcode id=62 lang=java
 *
 * [62] Unique Paths
 */

// @lc code=start

// iterative
// class Solution {
//     public int uniquePaths(int m, int n) {
//         if (m == 0 || n == 0) 
//             return 0;
//         // init
//         int[][] dp = new int[m][n];
//         for (int i = 0; i < m; i++)
//             dp[i][0] = 1;
//         for (int i = 0; i < n; i++)
//             dp[0][i] = 1;
//         // for loop to dp
//         for (int i = 1; i < m; i++) {
//             for (int j = 1; j < n; ++j) {
//                 // upper + left = current value
//                 dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
//             }
//         }
//         return dp[m - 1][n - 1];
//     }
// }

// use memo
class Solution {
    public int uniquePaths(int m, int n) {
        if (m == 0 || n == 0) 
            return 0;
        int[][] mem = new int[m][n];
        for (int i = 0; i < m; i++) { // init
            for (int j = 0; j < n; ++j) {
                mem[i][j] = -1;
            }
        }
        return numPaths(m - 1, n - 1, mem);
    }

    private int numPaths(int i, int j, int[][] mem) {
        if (i == 0 || j == 0) {
            return 1;
        }
        // first time meet, calculate it
        if (mem[i - 1][j] == -1)
        mem[i - 1][j] = numPaths(i - 1, j, mem);
        // first time meet, calculate it
        if (mem[i][j - 1] == -1)
            mem[i][j - 1] = numPaths(i, j - 1, mem);
        // not first time
        return mem[i - 1][j] + mem[i][j - 1];
    }
}

// math way
// public class Solution {
//     // Total permutations = (m + n)! / (m! * n!)
//     // 10! / 3! * 7!
//     // 10 * ... * 4 / 7 * ... * 1
//     public int uniquePaths(int m, int n) {
//         if (m == 1 || n == 1)
//             return 1;
//         // m = 3, n = 7
//         m--;
//         n--;
//         // 2 6
//         if (m < n) { // Swap, so that m is the bigger number
//             m = m + n;
//             n = m - n;
//             m = m - n;
//         }
//         // m is bigger, n is smaller
//         long res = 1;
//         int j = 1;
//         // i = 3, i <= 9, j = 1
//         for (int i = m + 1; i <= m + n; i++, j++) {
//             // Instead of taking factorial, keep on multiply & divide
//             res *= i;
//             res /= j;
//         }
//         // res = 1 * 3 / 1 *
//         return (int) res;
//     }
// }
// @lc code=end
