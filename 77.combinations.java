/*
 * @lc app=leetcode id=77 lang=java
 *
 * [77] Combinations
 */

// @lc code=start
class Solution {
    public List<List<Integer>> combine(int n, int k) {
        List<List<Integer>> list = new ArrayList<>();
        backtrack(list, new ArrayList<>(), 1, n, k);
        return list;
    }

    private void backtrack(List<List<Integer>> combs, List<Integer> comb, int start, int n, int k) {
        // reach the end
        if (k == 0) {
            combs.add(new ArrayList<Integer>(comb));
            return;
        }
        // for loop to loop over all n
        for (int i = start; i <= n; i++) {
            // add i to comb
            comb.add(i);
            // pass k - 1 to indicate one happened
            backtrack(combs, comb, i + 1, n, k - 1);
            // delete it from comb
            comb.remove(comb.size() - 1);
        }
    }
}
// @lc code=end
