/*
 * @lc app=leetcode id=4 lang=java
 *
 * [4] Median of Two Sorted Arrays
 */

// @lc code=start
// // need O(log(m+n))
// class Solution {
//     public double findMedianSortedArrays(int[] nums1, int[] nums2) {
//         // aa a aaaaaa
//         // bb b bb
//         // a + b / 2 in 
//         // if a > b 
//         // search()

//     }
// }

// shorterLeft <= longerRight && longerLeft <= shorterRight
// so we can make sure we binary search two arrays
// https://leetcode.com/problems/median-of-two-sorted-arrays/discuss/1701107/Java-Binary-Search-Explained
class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        if (nums1 == null && nums2 == null)
            return 0;
        
        // one of the array is empty
        if (nums1 == null) {
            int n = nums2.length;
            // 7 number
            // 0 1 2 3 4 5 6
            // 3 * 0.5 + 3 * 0.5
            return nums2[(n - 1) / 2] * 0.5 + nums2[n / 2] * 0.5;
            // 6 number 
            // 0 1 2 3 4 5
            // 2 * 0.5 + 3 * 0.5
        }

        if (nums2 == null) {
            int n = nums1.length;
            return nums1[(n - 1) / 2] * 0.5 + nums1[n / 2] * 0.5;
        }

        if (nums1.length > nums2.length) {
            return findMedianSortedArrays(nums2, nums1);
        }

        // choose shorter to binary search
        int n = nums1.length;
        int m = nums2.length;
        int left = 0;
        int right = n;

        // core code - very important
        while (left < right) {
            // i = n / 2
            // j = (n + m) / 2 - n / 2
            int i = (left + right) / 2;
            // i will increase, j will decrease if it's bigger
            // vice versa
            int j = (n + m) / 2 - i;
            System.out.println(i + " " + j);

            // binary search array 1 until left + left is medium
            if (nums1[i] < nums2[j - 1]) {
                left = i + 1;
            } else {
                right = i;
            }
        }

        // after this, we already filter out four part
        int first = left;
        int second = (n + m) / 2 - left;

        int shorterLeft = first == 0 ? Integer.MIN_VALUE : nums1[first - 1];
        int shorterRight = first == n ? Integer.MAX_VALUE : nums1[first];

        int longerLeft = second == 0 ? Integer.MIN_VALUE : nums2[second - 1];
        int longerRight = second == m ? Integer.MAX_VALUE : nums2[second];

        if ((n + m) % 2 == 1) {
            return Math.min(shorterRight, longerRight);
        } else {
            return Math.max(shorterLeft, longerLeft) * 0.5 + Math.min(shorterRight, longerRight) * 0.5;
        }
    }
}

// O(n+m)
// class Solution {
// public double findMedianSortedArrays(int[] nums1, int[] nums2) {
// int index1 = 0, index2 = 0, med1 = 0, med2 = 0;
// int length = nums1.length + nums2.length;

// for (int i = 0; i <= (length) / 2; i++) {
// med1 = med2;
// if (index1 == nums1.length) {
// med2 = nums2[index2];
// index2++;
// } else if (index2 == nums2.length) {
// med2 = nums1[index1];
// index1++;
// } else if (nums1[index1] < nums2[index2]) {
// med2 = nums1[index1];
// index1++;
// } else {
// med2 = nums2[index2];
// index2++;
// }
// }

// if ((length) % 2 == 0) {
// return (float) (med1 + med2) / 2;
// } else {
// return med2;
// }
// }
// }
// @lc code=end
