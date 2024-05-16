/*
 * @lc app=leetcode id=7 lang=cpp
 *
 * [7] Reverse Integer
 */

// @lc code=start

// #include <bits/stdc++.h>
#include <algorithm>
#include <climits>
#include <string>

using namespace std;

// class Solution {
//    public:
//     Idea: 1. int to string to int
//     int reverse(int x) {
//         // -9 -8 ... 0 ... 8 9 no need to reverse
//         if (x > -10 and x < 10) return x;

//         // store the sign of the number
//         int is_negative = x < 0 ? -1 : 1;

//         string str = to_string(abs(x));
//         // https://en.cppreference.com/w/cpp/string/basic_string/to_string
//         // std::string to_string( int value );
//         // https://en.cppreference.com/w/cpp/numeric/math/abs
//         // int       abs( int num );

//         std::reverse(begin(str), end(str));

//         if (str.size() >= 10 and str > "2147483648") {
//             // Handle overflow case
//             return 0;
//         }

//         return is_negative * stoi(str);
//     }
// };

class Solution {
   public:
    int reverse(int x) {
        // Second Idea: Use math loop and handle overflow
        int rev = 0;
        while (x != 0) {
            // use the modulo to get the last digit
            int pop = x % 10;
            // remove the last digit
            x /= 10;
            // now a int is divided to [x, pop]

            // handle overflow case
            // INT_MAX = 2147483647
            // INT_MIN = -2147483648

            // handle if rev is too big or too small
            // if rev is bigger than INT_MAX / 10, then rev * 10 will overflow
            if (rev > INT_MAX / 10) return 0;
            // similarly handle if rev is smaller than INT_MIN / 10
            if (rev < INT_MIN / 10) return 0;

            // handle if rev is equal to INT_MAX / 10 and have pop > 7
            // in this case INT_MAX = 2147483647 is not big enough to store the
            // result so return 0
            if (rev == INT_MAX / 10 and pop > 7) return 0;

            // similarly handle rev too small and pop < -8
            // then the result will be too small
            if (rev == INT_MIN / 10 and pop < -8) return 0;

            // if no overflow, append pop and continue
            rev = rev * 10 + pop;
        }
        return rev;
    }
};

// @lc code=end
