/*
 * @lc app=leetcode id=6 lang=cpp
 *
 * [6] Zigzag Conversion
 */

// @lc code=start

#include <string>
#include <vector>
using namespace std;

class Solution {
   public:
    string convert(string s, int numRows) {
        if (numRows == 1 || numRows >= s.length()) {
            return s;
        }

        // Idea: Use a vector of strings to store each row, then at the end concatenate all the rows
        vector<string> rows(numRows, "");

        // a loop to iterate over the string and fill the rows

        string result = "";

        return result;
    }
};
// @lc code=end
