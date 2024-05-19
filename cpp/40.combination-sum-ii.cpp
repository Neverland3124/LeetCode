/*
 * @lc app=leetcode id=40 lang=cpp
 *
 * [40] Combination Sum II
 */

// @lc code=start

#include <algorithm>
#include <set>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        // Note: can only use each number once
        vector<vector<int>> result;
        vector<int> candidate;
        sort(candidates.begin(), candidates.end());
        // here we don't remove duplicates because we can use a number in
        //  different position
        // candidates.erase(unique(candidates.begin(),
        //  candidates.end()), candidates.end());

        backtrack(candidates, target, result, candidate, 0);

        return result;
    }

    void backtrack(vector<int> candidates_list, int target,
                   vector<vector<int>>& result, vector<int> candidate,
                   int index) {
        if (target < 0) {
            return;
        } else if (target == 0) {
            result.push_back(candidate);
            return;
        } else {
            for (int i = index; i < candidates_list.size(); i++) {
                if (candidates_list[i] > target) {
                    break;
                }

                // consider candidates_list = [1,2,2,3], target = 6
                // result = [], candidate = [], index = 0
                // i = 0, index = 0
                // i = 1, index = 1

                // i > index happens when we are in the middle of backtracking
                //  we already have index = 1, i = 1 and finish the search, then
                //  we increase i to continue, where candidates_list[i] = 2 
                //  where we are having the duplicate, so we skip it

                // here the purpose is to avoid duplicates
                if (i > index && candidates_list[i] == candidates_list[i - 1]) {
                    continue;
                }

                candidate.push_back(candidates_list[i]);
                backtrack(candidates_list, target - candidates_list[i], result,
                          candidate, i + 1);
                // here we use i + 1 to avoid using the same number again
                candidate.pop_back();
            }
        }
    }
};
// @lc code=end
