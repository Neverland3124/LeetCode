#include <algorithm>
#include <set>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<vector<int>> permute(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> candidate;
        sort(candidates.begin(), candidates.end());
        candidates.erase(unique(candidates.begin(), candidates.end()),
                         candidates.end());
        backtrack(candidates, target, result, candidate, 0);
        return result;
    }

    void backtrack(vector<int> candidates_list, int target, vector<vector<int>>& result,
                   vector<int> candidate, int index) {
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
                candidate.push_back(candidates_list[i]);
                backtrack(candidates_list, target - candidates_list[i], result, candidate, i);
                candidate.pop_back();
            }
        }
    }
};