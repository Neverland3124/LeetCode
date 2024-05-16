/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 */

// @lc code=start
#include <string>
#include <vector>
using namespace std;

// class Solution {
// public:
//     auto longestPalindrome(string s) {
//         // Idea: every palindrome has a center, for every index we expend it to find the longest
//         palindrome
//         // then we find the max palindrome for all indexes, so we got the result
//         // handle edge case
//         if (s.length() <= 1) {
//             return s;
//         }

//         // auto helper function
//         // captures: [&] - capture all variables by reference (read-write)
//         // this function given a left and right, expand from center to find the longest
//         palindrome auto expand_from_center = [&](int left, int right) {
//             while (left >= 0 && right < s.length() && s[left] == s[right]) {
//                 left--;
//                 right++;
//             }
//             return s.substr(left + 1, right - left - 1);
//         };
//         // [a,a,b,b,a,a]
//         // if input is 0,1, can only get aa
//         // if input is 1,2, can get ""
//         // if input is 2,3, can get aabbaa
//         //  left = -1, right = 6
//         //  return s.substr(left + 1, right - left - 1);
//         //  return s.substr(-1 + 1, 6 - (-1) - 1); = (0, 6)
//         //  start position 0, length 6

//         std::string max_str = s.substr(0, 1);

//         for (int i = 0; i < s.length() - 1; i++) {
//             // O(n) loop over the whole string
//             std::string odd = expand_from_center(i, i);
//             // expand from center for odd length palindrome
//             std::string even = expand_from_center(i, i + 1);
//             // expand from center for even length palindrome

//             if (odd.length() > max_str.length()) {
//                 max_str = odd;
//             }
//             if (even.length() > max_str.length()) {
//                 max_str = even;
//             }
//             // get the max
//         }

//         return max_str;
//     }
// };

class Solution {
   public:
    auto longestPalindrome(string s) {
        // Second Idea: use dp
        if (s.length() <= 1) {
            return s;
        }

        int max_len = 1;
        int start = 0;
        int end = 0;
        // We initialize a boolean table dp and mark all the values as false.
        vector<vector<bool>> dp(s.length(), vector<bool>(s.length(), false));
        // Note: dp[x][y] == true means s[x:y] is a palindrome

        // This is a n*n table where every cell is default to false.
        // vector<int> vector3(5, 12); // size 5, value 12

        for (int i = 0; i < s.length(); ++i) {
            // mark diagonal as true
            // Every single character is a palindrome of length 1
            dp[i][i] = true;
            // loop over index that smaller than current
            for (int j = 0; j < i; ++j) {
                //
                if (s[j] == s[i] && (i - j <= 2 || dp[j + 1][i - 1])) {
                    // two cases:
                    // 1. s[j] == s[i] and i - j <= 2
                    //  which means it's either aa or aba
                    //  consider j as 0 and i as 1/2
                    // 2. s[j] == s[i] and dp[j + 1][i - 1] == true
                    //  which means s[j+1:i-1] is a palindrome
                    //  and also s[j] == s[i], so s[j:i] is a palindrome
                    dp[j][i] = true;
                    // if current palindrome is longer than max_len
                    // update max_len, start and end to return
                    if (i - j + 1 > max_len) {
                        max_len = i - j + 1;
                        start = j;
                        end = i;
                    }
                }
            }
        }

        return s.substr(start, end - start + 1);
    }
};

// Dynamic Programming
// 1. state the subproblem to solve
// 2. solving the original problem by subproblems
// 3. recursive formula to computer the subproblem
// @lc code=end
