/*
 * @lc app=leetcode id=90 lang=java
 *
 * [90] Subsets II
 */

// @lc code=start
class Solution {
    public List<List<Integer>> subsetsWithDup(int[] nums) {
        List<List<Integer>> list = new ArrayList<>();
        Arrays.sort(nums); // not necessary
        boolean[] used = new boolean[nums.length];

        // result list, templist, targetlist, start
        backtrack(list, new ArrayList<>(), nums, 0, used);
        return list;
    }

    private void backtrack(List<List<Integer>> list, List<Integer> tempList, int[] nums, int start, boolean[] used) {
        // add
        list.add(new ArrayList<>(tempList));
        // for loop start at i = start
        for (int i = start; i < nums.length; i++) {
            // add to the list
            if (used[i]) continue;

            // last branch of 122 tree, we don't include 2 because nums[1]=nums[2] = 2 but nums[1] is not visited
            // By using nums[i-1]==nums[i] && !used[i-1], we can make sure that 1b cannot be chosen before 1a
            if (i > 0 && nums[i - 1] == nums[i] && !used[i - 1]) continue;
            tempList.add(nums[i]);
            used[i] = true;
            backtrack(list, tempList, nums, i + 1, used);
            used[i] = false;
            tempList.remove(tempList.size() - 1);
        }
    }

}
// @lc code=end
