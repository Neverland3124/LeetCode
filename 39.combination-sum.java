/*
 * @lc app=leetcode id=39 lang=java
 *
 * [39] Combination Sum
 */

// @lc code=start

class Solution {
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        List<List<Integer>> res = new ArrayList<>();
        List<Integer> smallAns = new ArrayList<>();
        Arrays.sort(candidates);
        combinationSum(candidates, target, 0, smallAns, res);
        return res;
    }

    public void combinationSum(int[] arr, int tar, int idx, List<Integer> smallAns, List<List<Integer>> res) {
        if (tar == 0) res.add(new ArrayList<>(smallAns));
        else if(tar < 0);
        else{
            for (int i = idx; i < arr.length; ++i) {
                smallAns.add(arr[i]);
                combinationSum(arr, tar - arr[i], i, smallAns, res);
                smallAns.remove(smallAns.size() - 1);
            }
        }
        return;
    }
}
// 详细解析参见：
// https://labuladong.github.io/article/?qno=39



// class Solution {
    
//     public List<List<Integer>> combinationSum(int[] nums, int target) {
//         // sort nums
//         List<List<Integer>> list = new ArrayList<>();
//         Arrays.sort(nums);
//         // backtrack the target
//         backtrack(list, new ArrayList<>(), nums, target, 0);
//         return list;
//     }
    
//     private void backtrack(List<List<Integer>> list, List<Integer> tempList, int [] nums, int remain, int start){
//         // base case
//         if(remain < 0) return;
//         // base case valid
//         else if(remain == 0) list.add(new ArrayList<>(tempList));
//         else{ 
//             // for loop
//             for(int i = start; i < nums.length; i++){
//                 // add element
//                 tempList.add(nums[i]);
//                 // backtrack
//                 backtrack(list, tempList, nums, remain - nums[i], i); // not i + 1 because we can reuse same elements
//                 // remove element
//                 tempList.remove(tempList.size() - 1);
//             }
//         }
//     }
// }
// @lc code=end

