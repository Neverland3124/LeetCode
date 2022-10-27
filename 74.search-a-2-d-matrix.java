/*
 * @lc app=leetcode id=74 lang=java
 *
 * [74] Search a 2D Matrix
 */

// @lc code=start
// rubbish
// class Solution {
//     public boolean searchMatrix(int[][] matrix, int target) {
//         int i = 0, j = matrix[0].length - 1;
//         while (i < matrix.length && j >= 0) {
//             if (matrix[i][j] == target) {
//                 return true;
//             } else if (matrix[i][j] > target) {
//                 j--;
//             } else {
//                 i++;
//             }
//         }

//         return false;
//     }
// }

// binary search
class Solution {
    // TC: O(log(mn)), SC: O(1)
    public boolean searchMatrix(int[][] matrix, int target) {
        int rows = matrix.length, cols = matrix[0].length;
        int lo = 0, hi = rows * cols - 1;

        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            int num = matrix[mid / cols][mid % cols];
            if (num == target)
                return true;
            else if (num < target)
                lo = mid + 1;
            else
                hi = mid - 1;
        }
        return false;
    }
}

// my version - stupid
// class Solution {
//     public boolean searchMatrix(int[][] matrix, int target) {
//         int m = matrix.length;
//         // if target in matrix, it is at matrix[row][column]
//         // temp array to find corresponding row first
//         int[] temp = new int[m];
//         for(int i = 0; i < m; i++){
//             temp[i] = matrix[i][0];
//         }
//         int row = binary_search(temp, target); 
//         // first column in matrix[row]
//         int column = binary_search(matrix[row], target);
//         return matrix[row][column] == target;
//     }

//     public int binary_search(int[] arr, int target){
//         int left = 0, right = arr.length - 1;
//         while (left <= right) {
//             int mid = (left + right) / 2;
//             if (arr[mid] == target)
//                 return mid;
//             if (arr[mid] > target)
//                 right = mid - 1;
//             else
//                 left = mid + 1;
//         }
//         // we need left - 1 because we want value smaller than target
//         // if it is equal, it will return by (arr[mid] == target)
//         return left == 0 ? 0 : left - 1;
//     }
// }
// @lc code=end
