/*
 * @lc app=leetcode id=47 lang=cpp
 *
 * [47] Permutations II
 */

// @lc code=start
#include <algorithm>
#include <vector>
using namespace std;

// class Solution {
//    public:
//     vector<vector<int>> permuteUnique(vector<int>& nums) {
//         vector<vector<int>> result;
//         backtrack(nums, result, 0);

//         // Idea: Remove duplicate in the point of result
//         // i.e.: only remove duplicate in the result, don't change the way we
//         construct the result sort(result.begin(), result.end());
//         result.erase(unique(result.begin(), result.end()), result.end());
//         return result;
//     }

//     void backtrack(vector<int>& nums, vector<vector<int>>& result, int index)
//     {
//         if (index == nums.size() - 1) {
//             result.push_back(nums);
//             return;
//         }

//         for (int i = index; i < nums.size(); i++) {
//             swap(nums[index], nums[i]);
//             backtrack(nums, result, index + 1);
//             swap(nums[index], nums[i]);
//         }
//     }
// };

class Solution {
   public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
        // Second Idea: remove duplicate before we have the final result, 
        // which might be faster
        sort(nums.begin(), nums.end());
        backtrack(nums, result, 0);
        return result;
    }

    void backtrack(vector<int>& nums, vector<vector<int>>& result, int index) {
        if (index == nums.size() - 1) {
            result.push_back(nums);
            return;
        }

        for (int i = index; i < nums.size(); i++) {
            swap(nums[index], nums[i]);
            backtrack(nums, result, index + 1);
            swap(nums[index], nums[i]);
        }
    }
};
// @lc code=end
