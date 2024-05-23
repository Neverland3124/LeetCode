/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
 */

// @lc code=start

#include <vector>
using namespace std;

class Solution {
   public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;

        backtrack(result, current, nums, 0);
        return result;
    }

    void backtrack(vector<vector<int>>& result, vector<int>& current, vector<int>& nums,
                   int start) {
        // base case
        // also add the empty set []
        result.push_back(current);

        // loop
        for (int i = start; i < nums.size(); i++) {
            current.push_back(nums[i]);
            backtrack(result, current, nums, i + 1);
            current.pop_back();
        }
        // example: [1,2,3]
        // [1] -> [1,2] -> [1,2,3] -> [1,3] -> [2] -> [2,3] -> [3]
    }
};
// @lc code=end
