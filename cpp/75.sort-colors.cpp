/*
 * @lc app=leetcode id=75 lang=cpp
 *
 * [75] Sort Colors
 */

// @lc code=start

#include <vector>
using namespace std;

// class Solution {
//    public:
//     void sortColors(vector<int>& nums) {
//         // Note: sorting problem, need inplace sorting
//         // Idea: Since we only have 0,1,2, we just need to count the number of 0,1,2 and then
//         update
//         // the array
//         int count[3] = {0, 0, 0};
//         int index = 0;

//         // loop through the array and count the number of 0,1,2
//         for (int i = 0; i < nums.size(); i++) {
//             count[nums[i]]++;
//         }

//         // update array nums with the count
//         for (int i = 0; i < 3; i++) {
//             for (int j = 0; j < count[i]; j++) {
//                 nums[index++] = i;
//             }
//         }

//         return;
//     }
// };

#include <cassert>
class Solution {
   public:
    void sortColors(vector<int>& nums) {
        // Note: the first way can only be used when we know the range of the numbers, will need
        // another way
        // Second Idea: Dutch National Flag problem (from Leetcode)

        int zeros = 0;
        int ones = 0;
        int twos = nums.size() - 1;

        // loop until ones reach twos
        while (ones <= twos) {
            if (nums[ones] == 0) {
                // case ones read 0, what before ones is 0, so can swap with zeros
                swap(nums[zeros], nums[ones]);
                zeros++;
                ones++;
            } else if (nums[ones] == 1) {
                // cases ones read 1, just increase counter
                ones++;
            } else {
                assert(nums[ones] == 2);
                // cases ones read 2, we know twos is a counter from the right counter, so swap it
                // and decrease twos (place 2 to the end)
                swap(nums[ones], nums[twos]);
                twos--;
            }
        }
        // [2,0,2,1,1,0] 0 0 5
        // [0,0,2,1,1,2] 0 0 4
        // [0,0,2,1,1,2] 1 1 4
        // [0,0,2,1,1,2] 2 2 4
        // [0,0,1,1,2,2] 2 2 3
        // [0,0,1,1,2,2] 2 3 3
        // [0,0,1,1,2,2] 2 4 3
        return;
    }
};
// @lc code=end
