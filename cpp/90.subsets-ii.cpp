/*
 * @lc app=leetcode id=90 lang=cpp
 *
 * [90] Subsets II
 */

// @lc code=start

#include <algorithm>
#include <vector>
using namespace std;

// class Solution {
//    public:
//     vector<vector<int>> subsetsWithDup(vector<int>& nums) {
//         // Different from 78, now we can have duplicates
//         // we can have duplicate elements but we don't want duplicate in the result
//         vector<vector<int>> result;
//         vector<int> current;
//         // since we use nums[i] == nums[i - 1] to avoid case of duplicate, we will need sort nums
//         sort(nums.begin(), nums.end());

//         backtrack(result, current, nums, 0);
//         return result;
//     };
//     void backtrack(vector<vector<int>>& result, vector<int>& current, vector<int>& nums,
//                    int start) {
//         // base case
//         result.push_back(current);

//         // loop
//         for (int i = start; i < nums.size(); i++) {
//             if (i > start && nums[i] == nums[i - 1]) {
//                 continue;
//             }

//             current.push_back(nums[i]);
//             backtrack(result, current, nums, i + 1);
//             current.pop_back();
//         }
//         // example:
//         // [1,2,2] -> [] -> [1] -> [1,2] -> [1,2,2] -> [2] -> [2,2]
//     }
// };

#include <set>
class Solution {
   public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> result_set;
        vector<int> current;
        sort(nums.begin(), nums.end());

        int index = 0;
        backtrack(result_set, current, nums, index);

        vector<vector<int>> result_vector(result_set.begin(), result_set.end());
        return result_vector;
    }

    void backtrack(set<vector<int>>& result_set, vector<int>& current, vector<int>& nums,
                   int index) {
        if (index == nums.size()) {
            result_set.insert(current);
            return;
        }
        // Note: the first backtrack to represent the choice that exclude the index element
        // second to represent the choice of include the index element
        // Hard to manipulate duplicate, so use set
        backtrack(result_set, current, nums, index + 1);
        current.push_back(nums[index]);
        backtrack(result_set, current, nums, index + 1);
        // if current is pass by value, no need to pop back
        current.pop_back();
    }
};
// @lc code=end
