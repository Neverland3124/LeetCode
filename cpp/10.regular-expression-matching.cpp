/*
 * @lc app=leetcode id=10 lang=cpp
 *
 * [10] Regular Expression Matching
 */

// @lc code=start

#include <string>
#include <vector>
using namespace std;

class Solution {
   public:
    bool isMatch(string s, string p) {
        // Idea: Use dynamic programming
        // subproblem: dp[i][j] is true if s[0..i-1] matches p[0..j-1] (p is the
        // pattern)
        // original problem by subproblem: dp[n][m]
        // recursive formula:
        //  first consider j-1 is not * case
        //   since j-1 is not *, then either they equal or p[j-1] is '.'
        //   dp[i][j] = dp[i-1][j-1] && (s[i-1] == p[j-1] || p[j-1] == '.')
        //  then consider j-1 is * case
        //   if j-1 is *, then we need to consider two cases:
        //    1. if the * is not used (can match zero or more things), then we
        //    just ignore the last two characters
        //     i.e. dp[i][j] = dp[i][j-2]
        //    2. if the * is used, then p[j-2] must be used to match s[i-1]
        //     i.e. dp[i][j] = dp[i-1][j] && (s[i-1] == p[j-2] || p[j-2] == '.')
        //     s="pp", p="p*", so * much be used, and "p" should match "p*" as
        //     well

        // s "abccc"
        // p "abc*"
        // dp[4][4]
        // s[3] = c, p[3] = *

        // s "zxcdsfsdf"
        // p "zx.*"
        // dp[4][4]
        // s[3] = d, p[2] = .
        // dp[3][4]

        // aa
        // a*
        // dp[2][2] = true
        // s[1] = a, p[1] = a
        // dp[1][2] && (s[0] == p[0] || p[0] == '.') = true
        // dp[1][2] (also have *, but * is not used) = dp[1][0] && (s[0] == p[0]
        // || p[0] == '.')

        // init variables
        int n = s.length(), m = p.length();
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));

        // set default values
        dp[0][0] = true;
        // if s is empty, we need to check if p is like "a*" because it can
        // match empty string
        // no need to check dp[0][1] because it is always false "*" is invalid
        for (int i = 2; i <= m; i++) {
            if (p[i - 1] == '*') {
                dp[0][i] = dp[0][i - 2];
            }
        }

        // need to fill first row and first column
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                // update dp[i][j]
                if (p[j - 1] == '*') {
                    if (j >= 2) {
                        dp[i][j] = dp[i][j - 2] ||
                                   (s[i - 1] == p[j - 2] || p[j - 2] == '.') &&
                                       dp[i - 1][j];
                    } else {
                        dp[i][j] = false;
                    }
                } else {
                    dp[i][j] = dp[i - 1][j - 1] &&
                               (s[i - 1] == p[j - 1] || p[j - 1] == '.');
                }
            }
        }

        return dp[n][m];
    }
};
// @lc code=end
