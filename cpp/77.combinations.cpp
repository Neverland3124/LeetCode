/*
 * @lc app=leetcode id=77 lang=cpp
 *
 * [77] Combinations
 */

// @lc code=start

#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        // k numbers chosen from the range [1, n]
        // Input: n = 4, k = 2
        // Output: [[1,2],[1,3],[1,4],[2,3],[2,4],[3,4]
        vector<vector<int>> result;
        vector<int> current;

        backtrack(result, current, 1, n, k);
        return result;
    }

    void backtrack(vector<vector<int>>& result, vector<int>& current, int start, int n, int k) {
        if (current.size() == k) {
            result.push_back(current);
            return;
        }

        for (int i = start; i <= n; i++) {
            // put i in to the current combination
            current.push_back(i);
            // continue to the next number
            backtrack(result, current, i + 1, n, k);
            // pop it out
            current.pop_back();
        }

        // example:
        // treat n = 4 as [1, 2, 3, 4]
        // a1 a2 [1, 2] r2 a3 [1, 3] r3 a4 [1, 4] r4 r1
        // a2 a3 [2, 3] r3 a4 [2, 4] r4 r2
        // a3 a4 [3, 4] r4 r3
    }
};
// @lc code=end

