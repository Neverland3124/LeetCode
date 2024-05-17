/*
 * @lc app=leetcode id=8 lang=cpp
 *
 * [8] String to Integer (atoi)
 */

// @lc code=start

#include <climits>
#include <string>
using namespace std;

// Idea: Use long to store result to avoid overflow
//  and also git rid of leading zeros, spaces, +- at the beginning
class Solution {
   public:
    int myAtoi(string s) {
        int i = 0;
        int sign = 1;
        long result = 0;

        // skip white spaces
        while (i < s.length() && s[i] == ' ') i++;

        // check sign for one time
        if (s[i] == '-') {
            sign = -1;
            i++;
        } else if (s[i] == '+') {
            i++;
        }

        // start loop
        while (i < s.length()) {
            if (s[i] >= '0' && s[i] <= '9') {
                result = result * 10 + (s[i] - '0');
                // when result is greater than INT_MAX or INT_MIN, directly
                // return
                if (result > INT_MAX && sign == -1)
                    return INT_MIN;
                else if (result > INT_MAX && sign == 1)
                    return INT_MAX;
                i++;
            } else {
                return result * sign;
            }
        }
        return (int)result * sign;
    }
};
// @lc code=end
