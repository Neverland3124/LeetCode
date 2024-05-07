/*
 * @lc app=leetcode id=40 lang=java
 *
 * [40] Combination Sum II
 */

// @lc code=start
class Solution {
    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        List<List<Integer>> res = new ArrayList<>();
        Arrays.sort(candidates);
        combinationSum2(candidates, target, 0, new ArrayList<>(), res);
        return res;
    }

    public void combinationSum2(int[] arr, int tar, int idx, List<Integer> temp_list, List<List<Integer>> res) {
        if (tar == 0) {
            ArrayList<Integer> base = new ArrayList<>(temp_list);
            res.add(base);
            return;
        } else if (tar < 0) return;
        // a boolean array to mark visited or not
        boolean[] visited = new boolean[50];
        for (int i = idx; i < arr.length; ++i) {
            if (visited[arr[i]]) continue;
            visited[arr[i]] = true;
            temp_list.add(arr[i]);
            // target array, target number, index (start + 1), temp, result
            combinationSum2(arr, tar - arr[i], i + 1, temp_list, res);
            temp_list.remove(temp_list.size() - 1);
        }
    }
}
// @lc code=end

