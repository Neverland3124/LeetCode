/*
 * @lc app=leetcode id=39 lang=cpp
 *
 * [39] Combination Sum
 */

// @lc code=start

#include <algorithm>
#include <set>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        // Note: tag as backtracing and BDFS, guess we will try numbers until
        // we found the target is not possible to backtrack?
        // Another way is to use dynamic programming

        vector<vector<int>> result;
        vector<int> candidate;
        // sort the candidates and remove duplicates
        sort(candidates.begin(), candidates.end());
        // std::unique reorders the vector so that the duplicates are moved to
        // the end and returns an iterator to the new end of the vector
        candidates.erase(unique(candidates.begin(), candidates.end()),
                         candidates.end());
        // by this way, we have erase.begin on the start of the duplicates and
        // erase.end on the end of the vector (end of duplicates as well)

        // another way to use set to sort
        // std::set<int> s(candidates.begin(), candidates.end());
        // candidates.assign(s.begin(), s.end());

        backtrack(candidates, target, result, candidate, 0);
        return result;
    }

    /**
     * @brief Recursively finds all unique combinations in `c` where the
     * candidate numbers sum to a given target.
     *
     * @param candidates_list The input list of candidate numbers.
     * @param target The target sum we're trying to reach.
     * @param result A reference to a 2D vector where the function will store
     * all unique combinations that sum to the target.
     * @param candidate The current combination of numbers. It's initially empty
     * and gets filled as the function explores different combinations.
     * @param index The current index in `c` that the function is considering to
     * add to the current combination.
     *
     * @return void
     */
    void backtrack(vector<int> candidates_list, int target, vector<vector<int>>& result,
                   vector<int> candidate, int index) {
        // recursion until find target
        //  or not possible to find target in current path
        if (target < 0) {
            return;
        } else if (target == 0) {
            result.push_back(candidate);
            return;
        } else {
            for (int i = index; i < candidates_list.size(); i++) {
                if (candidates_list[i] > target) {
                    // An impossible path, no need to verify
                    // and later numbers are bigger so no need to check
                    // return also work but is slower
                    break;
                }
                // put the current number into the candidate
                candidate.push_back(candidates_list[i]);
                backtrack(candidates_list, target - candidates_list[i], result, candidate, i);
                // after backtrack, we either have add the possible combination,
                // or no combination exists, remove the candidate to next loop
                candidate.pop_back();
            }
        }
    }
};
// @lc code=end
