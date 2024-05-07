/*
 * @lc app=leetcode id=78 lang=java
 *
 * [78] Subsets
 */

// @lc code=start
class Solution {
    public List<List<Integer>> subsets(int[] nums) {
        List<List<Integer>> list = new ArrayList<>();
        Arrays.sort(nums); // not necessary
        // result list, templist, targetlist, start
        backtrack(list, new ArrayList<>(), nums, 0);
        return list;
    }

    private void backtrack(List<List<Integer>> list, List<Integer> tempList, int[] nums, int start) {
        // add
        list.add(new ArrayList<>(tempList));
        // for loop start at i = start
        for (int i = start; i < nums.length; i++) {
            // add to the list
            tempList.add(nums[i]);
            backtrack(list, tempList, nums, i + 1);
            // remove last one
            tempList.remove(tempList.size() - 1);
        }
    }
}
// @lc code=end
