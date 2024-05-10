/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */

// @lc code=start
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

// Solution 1: use a unordered set to store the character
//  when we meet repeated, we start to remove the leftmost character
// class Solution {
//    public:
//     int lengthOfLongestSubstring(string s) {
//         // Idea: use a hash table to store the character, if one repeat twice,
//         // then return the size of the hash table

//         // However, cpp seems don't have inbuilt hash table, so we use something
//         // else to store the character and also the count

//         int n = s.length();
//         int maxLength = 0;
//         unordered_set<char> charSet;
//         // std::set<char> is a sorted set of unique elements, but it's slower
//         // than unordered_set
//         int left = 0;

//         for (int i = 0; i < n; i++) {
//             if (charSet.count(s[i]) == 0) {
//                 // case 1: if the character is not in the set, insert it to the set
//                 charSet.insert(s[i]);
//                 // take the max of current or the max
//                 maxLength = max(maxLength, i - left + 1);
//             } else {
//                 // case 2: if the character is in the set, remove the leftmost
//                 // until it's not in the set to start a new substring
//                 while (charSet.count(s[i])) {
//                     charSet.erase(s[left]);
//                     left++;
//                 }
//                 charSet.insert(s[i]);
//             }
//         }
//         return maxLength;
//     }
// };

// Solution 2: use a vector of char to store the position of last occurrence of the character
class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int maxLength = 0;
        vector<int> charIndex(128, -1);
        // Note: here charIndex is the name of the variable, the input is 128 and -1, represent an
        // initial size of 128, and initializing all elements to -1.
        // Why we can use 128 is because the ASCII table has 128 characters, 128 is big enough
        int left = 0;

        for (int right = 0; right < n; right++) {
            // loop over the whole string

            // charIndex[s[right]] will update the last position of the character, if it is bigger
            // than left, then the left need to update because we no longer record character's old
            // position
            if (charIndex[s[right]] >= left) {
                // s[right] is the current character
                // if the character have index bigger than left, if means it's repeated
                left = charIndex[s[right]] + 1;
            }
            // after update left, now we update the last position of the character
            charIndex[s[right]] = right;
            // and calculate the max length
            maxLength = max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};
// @lc code=end
