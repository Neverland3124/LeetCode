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

        // Idea: Use a vector of strings to store each row, then at the end
        // concatenate all the rows
        vector<string> rows(numRows, "");
        int current_row = 0;
        bool direction_down = false;
        // set to false for first loop to start increase current_row

        // a loop to iterate over the string and fill the rows
        for (int i = 0; i < s.length(); i++) {
            // if we are now at first or last row, reverse the direction
            if (current_row == 0 || current_row == numRows - 1) {
                direction_down = !direction_down;
            }

            // append the character to the vector of strings
            rows[current_row] += s[i];

            // need to move to the next row
            if (direction_down) {
                current_row++;
            } else {
                current_row--;
            }

        }
            
        string result = "";

        for(int i = 0; i < numRows; i++) {
            result += rows[i];
        }

        return result;
    }
};
// @lc code=end
