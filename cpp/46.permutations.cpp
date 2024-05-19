/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 */

// @lc code=start
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        backtrack(nums, result, 0);
        return result;
    }

    void backtrack(vector<int>& nums, vector<vector<int>>& result,
                   int index) {
        if (index == nums.size() - 1) {
            result.push_back(nums);
            return;
        }

        for (int i = index; index < nums.size(); index++) {
            swap(nums[index], nums[i]);
            backtrack(nums, result, index + 1);
            swap(nums[index], nums[i]);
        }
    }
};
// @lc code=end
