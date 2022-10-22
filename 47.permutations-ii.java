/*
 * @lc app=leetcode id=47 lang=java
 *
 * [47] Permutations II
 */

// @lc code=start
class Solution {
    public List<List<Integer>> permuteUnique(int[] nums) {
        List<List<Integer>> result = new ArrayList<List<Integer>>();
        LinkedList<Integer> per = new LinkedList<Integer>();
        HashMap<Integer, Integer> map = new HashMap<Integer, Integer>();
        
        // store the nums in a hashmap to trace the number
        for (int n : nums) {
            if (!map.containsKey(n)) {
                map.put(n, 0);
            }
            map.put(n, map.get(n) + 1);
        }

        backtrack(nums.length, map, per, result);
        return result;
    }

    private void backtrack(int length, HashMap<Integer, Integer> map, LinkedList<Integer> temp_list, List<List<Integer>> result) {
        // same as distinct one
        if (temp_list.size() == length) {
            result.add(new ArrayList<Integer>(temp_list));
            return;
        }
        // if their is one in the entry
        for (Map.Entry<Integer, Integer> entry : map.entrySet()) {
            // value is 0, exist two such value
            if (entry.getValue() == 0) {
                continue;
            }
            entry.setValue(entry.getValue() - 1);

            // add to the temp_list
            temp_list.add(entry.getKey());
            backtrack(length, map, temp_list, result);
            temp_list.removeLast();

            entry.setValue(entry.getValue() + 1);
        }

    }
}


// //similar to combine ii
// public class Solution {
//     public List<List<Integer>> permuteUnique(int[] nums) {
//         List<List<Integer>> res = new ArrayList<List<Integer>>();
//         if(nums==null || nums.length==0) return res;
//         boolean[] used = new boolean[nums.length];
//         List<Integer> list = new ArrayList<Integer>();
//         Arrays.sort(nums);
//         dfs(nums, used, list, res);
//         return res;
//     }

//     public void dfs(int[] nums, boolean[] used, List<Integer> list, List<List<Integer>> res){
//         if(list.size()==nums.length){
//             res.add(new ArrayList<Integer>(list));
//             return;
//         }
//         for(int i=0;i<nums.length;i++){
//             if(used[i]) continue;
//             if(i>0 &&nums[i-1]==nums[i] && !used[i-1]) continue;
//             used[i]=true;
//             list.add(nums[i]);
//             dfs(nums,used,list,res);
//             used[i]=false;
//             list.remove(list.size()-1);
//         }
//     }
// }

// @lc code=end
