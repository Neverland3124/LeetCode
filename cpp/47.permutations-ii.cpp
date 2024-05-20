/*
 * @lc app=leetcode id=47 lang=cpp
 *
 * [47] Permutations II
 */

// @lc code=start
#include <algorithm>
#include <iostream>
#include <set>
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

#include <algorithm>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        // Second Idea: Use a totally different way dell with swap and remove duplicate is very hard
        // to implement now we choose now to use swap but just add item to the vector
        vector<vector<int>> result;
        vector<bool> used(nums.size(), false);
        vector<int> currentPermutation;

        sort(nums.begin(), nums.end());
        // don't use index anymore, just currentPermutation array
        backtrack(nums, result, currentPermutation, used);

        return result;
    }

   private:
    void backtrack(vector<int>& nums, vector<vector<int>>& result, vector<int>& currentPermutation,
                   vector<bool>& used) {
        // base case to push to result
        if (currentPermutation.size() == nums.size()) {
            result.push_back(currentPermutation);
            return;
        }

        for (int i = 0; i < nums.size(); ++i) {
            if (used[i]) continue;

            // below is the only line change to prevent duplicate
            // what we want to prevent here is that position 0 and 1 have the same element, then
            // [p0, p1, p2] will be same as [p1, p0, p2] since both are [1, 1, 2]

            if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1]) {
                // nums are sorted, and i is not used by previous condition
                // i > 0 because 0 will not be duplicate with others
                // in the for loop, it might happens that we previous i-1 is set back to false and
                // then we use the current i, which is exactly the case of [p1, p0, p2] which we
                // should avoid, so use this continue to avoid this
                continue;
            }

            used[i] = true;
            currentPermutation.push_back(nums[i]);
            backtrack(nums, result, currentPermutation, used);
            used[i] = false;
            currentPermutation.pop_back();
        }
    }
};

// @lc code=end
