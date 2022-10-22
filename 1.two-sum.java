// import java.util.Map;

/*
 * @lc app=leetcode id=1 lang=java
 *
 * [1] Two Sum
 */

// @lc code=start
public class Solution {
    public int[] twoSum(int[] nums, int target) {
		int[] ans = new int[2];
		HashMap<Integer, Integer> map = new HashMap<>();

		for (int index = 0; index < nums.length; index++) {
			if (!map.containsKey(nums[index])) {
				map.put(target - nums[index], index);
			} else {
                ans[0] = map.get(nums[index]);
				ans[1] = index;
				break;
                
			}
		}
        
		return ans;
	}
}
// @lc code=end

