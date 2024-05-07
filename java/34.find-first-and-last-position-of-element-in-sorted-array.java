/*
 * @lc app=leetcode id=34 lang=java
 *
 * [34] Find First and Last Position of Element in Sorted Array
 */

// @lc code=start

// clean solution - didn't learn
// public class Solution {
//     public int[] searchRange(int[] nums, int target) {
//         int l = 0;
//         int r = nums.length - 1;
//         while (l <= r) {
//             int mid = (l + r) / 2;
//             if (nums[mid] == target) {
//                 if (nums[l] == target && nums[r] == target) {
//                     return new int[] { l, r };
//                 }
//                 if (nums[l] < target) {
//                     l++;
//                 }
//                 if (nums[r] > target) {
//                     r--;
//                 }
//             } else if (target < nums[mid]) {
//                 r = mid - 1;
//             } else {
//                 l = mid + 1;
//             }
//         }
//         return new int[] { -1, -1 };
//     }
// }

// linear
// class Solution {
// public int[] searchRange(int[] nums, int target) {
// int[] result = new int[2];
// result[0] = -1;
// result[1] = -1;
// // int res[] = { -1, -1 };
// for(int i = 0; i < nums.length; i++){
// if(nums[i] == target && result[0] == -1){
// result[0] = i;
// }
// if(nums[i] == target){
// result[1] = i;
// }
// }
// return result;
// }
// }

// todo: log n: binary search
class Solution {
    public int[] searchRange(int[] nums, int target) {
        int res[] = { -1, -1 };
        if (nums.length == 0)
            return res;
        // nums target - 0.5
        // find the
        // 7.5 vvs 8.5
        // 7.5 < 8
        // anything between target and target + 1 is okay
        int left = binarySearch(nums, target - 0.1);
        int right = binarySearch(nums, target + 0.1);
        // left == right, case that we cannot find the node
        // if they equal, then we cannot find that one
        if (right - left == 0)
            return res;
        res[0] = left;
        res[1] = right - 1;
        return res;
    }

    // find 8.1
    // l = 0, r = 5
    // m = 2, l = 3, r = 5, m = 4, l = r = 5, m = 5, r = 4, return 5

    private int binarySearch(int[] arr, double target) {
        int left = 0;
        int right = arr.length - 1;
        while (left <= right) {
            // middle one
            int mid = (left + right) / 2;
            // search left part
            if (arr[mid] > target)
                right = mid - 1;
            // search right part
            else if (arr[mid] < target)
                left = mid + 1;

            // if they equal
            // they will not equal
        }
        // return the one we find
        // where left > right
        // in this case, a b c b = left = right before, if b > target, return b, if b <
        // target, return b + 1 treat b + 1 as b since we are return right -1 in res
        return left;
    }
}

// general
// class Solution {
// public int[] searchRange(int[] A, int target) {
// int start = firstGreaterEqual(A, target);
// if (start == A.length || A[start] != target) {
// return new int[]{-1, -1};
// }
// // firstGreaterEqual(A, target + 1) - 1 will return next value - 1
// return new int[]{start, firstGreaterEqual(A, target + 1) - 1};
// }

// //find the first number that is greater than or equal to target.
// //could return A.length if target is greater than A[A.length-1].
// //actually this is the same as lower_bound in C++ STL.
// private static int firstGreaterEqual(int[] A, int target) {
// int low = 0, high = A.length;
// while (low < high) {
// int mid = (low + high) / 2;
// //low <= mid < high
// if (A[mid] < target) {
// low = mid + 1;
// } else {
// //should not be mid-1 when A[mid]==target.
// //could be mid even if A[mid]>target because mid<high.
// high = mid;
// }
// }
// return low;
// }
// }

// @lc code=end
