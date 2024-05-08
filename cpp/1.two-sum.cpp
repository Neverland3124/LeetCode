/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */

// @lc code=start
// Note: First leetcode problem start
// use clang formatter
// include vector and std to avoid issue in the code, not need in solution
#include <vector>
using namespace std;

class Solution {
   public:
    // TODO: what is public, what else do we have?
    // TODO: what is vector? here it looks like have a generic of int
    vector<int> twoSum(vector<int> &nums, int target) {
        // TODO: why pass nums by reference?
        // Start here
        int n = nums.size();
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (nums[i] + nums[j] == target) {
                    // TODO: how to return vector of int?
                    return {i, j};
                }
            }
        }
        return {};
    }
};
// @lc code=end
