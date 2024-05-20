/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 */

// @lc code=start
#include <algorithm>
#include <cassert>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        backtrack(nums, result, 0);
        return result;
    }

    // when index == nums.size() - 1, backtrack will add the current nums to
    // result
    // when index < nums.size() - 1, we will be swapping index with all
    // elements after index and eventually add nums to result
    void backtrack(vector<int>& nums, vector<vector<int>>& result, int index) {
        if (index == nums.size() - 1) {
            result.push_back(nums);
            return;
        }

        assert(index < nums.size());

        // the following loop will swap index with all elements that after
        // index, then recursively call backtrack with index + 1
        // by doing so,
        // [1, index, 3, 4] will have index swap with 3, 4
        // [1, 3, index, 4] with new index at position 3
        // this will go over the original 1324 and swapped 1342
        // [1, 3, 4, index] with new index at position 4
        // so generally this will work because the new backtrack will return the
        // permutation of rest of nums for loop will return the permutation of
        // current index of the nums
        for (int i = index; i < nums.size(); i++) {
            // swap(x, y) will swap x and y in the array nums
            swap(nums[index], nums[i]);
            backtrack(nums, result, index + 1);
            swap(nums[index], nums[i]);
        }
        // nums = [1,2,3], index = 0
        // [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,2,1],[3,1,2]]
        // first index then i
        // a00 a11 a22 r22 [1,2,3] a12 r12[1,3,2] r11
        // a01 a11 a22 r22 [2,1,3] a12 r12[2,3,1] r11
        // a02 a11 a22 r22 [3,2,1] a12 r12[3,1,2] r11
        // end
    }
};
// @lc code=end
