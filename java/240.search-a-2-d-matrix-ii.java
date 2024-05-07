/*
 * @lc app=leetcode id=240 lang=java
 *
 * [240] Search a 2D Matrix II
 */

// @lc code=start
// binary search
// class Solution {
//     public boolean searchMatrix(int[][] matrix, int target) {
//         for (int i = 0; i < matrix.length; i++) {
//             int left = 0, right = matrix[i].length - 1;
//             while (left <= right) {
//                 int m = (left + right) / 2;
//                 if (matrix[i][m] == target)
//                     return true;
//                 else if (matrix[i][m] < target)
//                     left = m + 1;
//                 else
//                     right = m - 1; 
//             }
//         }
//         return false;
//     }
// }

// m + n
class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        int row = matrix.length, col = matrix[0].length;
        int i = 0,  j = col - 1;

        // either go up or go right
        while (i < row && j >= 0) {
            if (matrix[i][j] == target)
                return true;
            else if (matrix[i][j] < target)
                i++;
            else
                j--;
        }
        return false;
    }
}

// @lc code=end
