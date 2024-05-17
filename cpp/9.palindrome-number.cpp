/*
 * @lc app=leetcode id=9 lang=cpp
 *
 * [9] Palindrome Number
 */

// @lc code=start

// class Solution {
//    public:
//     bool isPalindrome(int x) {
//         if (x < 0) return false;

//         // First Idea: Store a reversed copy of the number and compare it
//         with
//         // the original

//         long reverse = 0;
//         int copy = x;

//         while (copy > 0) {
//             reverse = (reverse * 10) + (copy % 10);
//             copy /= 10;
//         }

//         return reverse == x;
//     }
// };

class Solution {
   public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        // TODO: why need handle this special case?
        if (x % 10 == 0 && x != 0) return false;

        // Second Idea: Reverse only half of the number and compare it with the
        // other half

        // on this way we only need int not long
        int reversed = 0;
        while (x > reversed) {
            reversed = reversed * 10 + x % 10;
            // module 10 to get the last digit of x
            x /= 10;
        }
        // two cases: 121 or 1221
        // x == reversed for even number of digits case
        // x == reversed / 10 for odd number of digits case (1 compare with 12)
        return (x == reversed) || (x == reversed / 10);
    }
};
// @lc code=end
