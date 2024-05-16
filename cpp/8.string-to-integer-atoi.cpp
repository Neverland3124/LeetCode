/*
 * @lc app=leetcode id=8 lang=cpp
 *
 * [8] String to Integer (atoi)
 */

// @lc code=start

#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        string result = "";
        int is_negative = 1;
        bool valid = false;

        for (int i = 0; i < s.length(); i++) {
            if (s[0] == '-') {
                is_negative = -1;
                continue;
            }

            // [-0 +9]
            if (valid == false and (s[i] == '0' || s[i] == ' ')) {
                // skip leading zeros and spaces
                continue;
            }

            if (valid == false and (s[i] < '0' || s[i] > '9')) {
                // if first non-space character is not a valid number
                return 0;
            }

            if (valid == false and (s[i] < '0' || s[i] > '9')) {
                // if first non-space character is not a valid number
                return 0;
            }

            if (s[i] >= '0' and s[i] <= '9') {
                valid = true;
                result += s[i];    
            }

            // loop 

        }

        // print result
        cout << result << endl;
        // print result after stoi
        cout << stoi(result) << endl;
        return abs(stoi(result)) * is_negative;
    }
};


// Idea: Use long to store result to avoid overflow
//  and also git rid of leading zeros, spaces, +- at the beginning
// #include <climits>
// class Solution {
//    public:
//     int myAtoi(string s) {
//         int i = 0;
//         int sign = 1;
//         long result = 0;

//         // skip white spaces
//         while (i < s.length() && s[i] == ' ') i++;

//         // check sign for one time
//         if (s[i] == '-') {
//             sign = -1;
//             i++;
//         } else if (s[i] == '+') {
//             i++;
//         }

//         // start loop
//         while (i < s.length()) {
//             if (s[i] >= '0' && s[i] <= '9') {
//                 result = result * 10 + (s[i] - '0');
//                 // when result is greater than INT_MAX or INT_MIN, directly return
//                 if (result > INT_MAX && sign == -1)
//                     return INT_MIN;
//                 else if (result > INT_MAX && sign == 1)
//                     return INT_MAX;
//                 i++;
//             } else {
//                 return result * sign;
//             }
//         }
//         return (int) result * sign;
//     }
// };
// @lc code=end

