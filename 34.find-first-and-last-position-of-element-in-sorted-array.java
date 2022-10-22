/*
 * @lc app=leetcode id=34 lang=java
 *
 * [34] Find First and Last Position of Element in Sorted Array
 */

// @lc code=start
// linear
// class Solution {
//     public int[] searchRange(int[] nums, int target) {
//         int[] result = new int[2];
//         result[0] = -1;
//         result[1] = -1;
//         // int res[] = { -1, -1 };
//         for(int i = 0; i < nums.length; i++){
//             if(nums[i] == target && result[0] == -1){
//                 result[0] = i;
//             }
//             if(nums[i] == target){
//                 result[1] = i;
//             }
//         }
//         return result;
//     }
// }


// todo: log n: binary search 
class Solution {
    public int[] searchRange(int[] nums, int target) {
        int res[] = { -1, -1 };
        if (nums.length == 0)
            return res;
        int left = binarySearch(nums, target - 0.5);
        int right = binarySearch(nums, target + 0.5);
        if (right - left == 0)
            return res;
        res[0] = left;
        res[1] = right - 1;
        return res;
    }

    private int binarySearch(int[] arr, double target) {
        int left = 0;
        int right = arr.length - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (arr[mid] > target)
                right = mid - 1;
            else if (arr[mid] < target)
                left = mid + 1;
        }
        return left;
    }
}


// general
// public class Solution {
// 	public int[] searchRange(int[] A, int target) {
// 		int start = Solution.firstGreaterEqual(A, target);
// 		if (start == A.length || A[start] != target) {
// 			return new int[]{-1, -1};
// 		}
// 		return new int[]{start, Solution.firstGreaterEqual(A, target + 1) - 1};
// 	}

// 	//find the first number that is greater than or equal to target.
// 	//could return A.length if target is greater than A[A.length-1].
// 	//actually this is the same as lower_bound in C++ STL.
// 	private static int firstGreaterEqual(int[] A, int target) {
// 		int low = 0, high = A.length;
// 		while (low < high) {
// 			int mid = low + ((high - low) >> 1);
// 			//low <= mid < high
// 			if (A[mid] < target) {
// 				low = mid + 1;
// 			} else {
// 				//should not be mid-1 when A[mid]==target.
// 				//could be mid even if A[mid]>target because mid<high.
// 				high = mid;
// 			}
// 		}
// 		return low;
// 	}
// }
// @lc code=end
