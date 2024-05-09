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
    // what is vector? int is a generic type in vector
    // can use double as well
    // vector is a dynamic array in C++ STL
    vector<int> twoSum(vector<int> &nums, int target) {
        // why pass nums by reference?
        // nums is passed by reference to avoid copying the entire vector
        int n = nums.size();
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (nums[i] + nums[j] == target) {
                    // how to return vector of int?
                    // return {i, j};
                    // both working
                    std::vector<int> vec = {i, j};
                    return vec;
                }
            }
        }
        return {};
    }
};
// @lc code=end
