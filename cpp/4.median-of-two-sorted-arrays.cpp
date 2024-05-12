/*
 * @lc app=leetcode id=4 lang=cpp
 *
 * [4] Median of Two Sorted Arrays
 */

// @lc code=start

#include <climits>
#include <vector>
using namespace std;

class Solution {
   public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // Idea: We are given two sorted arrays, we will need to somehow merge them together and
        // take the median to return Idea1: the time complexity of merge two sorted arrays is
        // O(m+n), but we are required to do it in O(log(m+n)), so need another way Idea2: use the
        // characteristic of the median and binary search

        int n1 = nums1.size(), n2 = nums2.size();

        // Ensure nums1 is the smaller array for simplicity
        if (n1 > n2) return findMedianSortedArrays(nums2, nums1);

        int n = n1 + n2;               // size
        int left = (n1 + n2 + 1) / 2;  // Calculate the left partition size
        int low = 0, high = n1;        // low is 0, high is size of longer array

        // loop until binary search is complete
        while (low <= high) {
            int mid1 = (low + high) >> 1;  // Calculate mid index for nums1
            // Note: same as / 2 but faster
            int mid2 = left - mid1;  // Calculate mid index for nums2
            // mid 2 = (n1 + n2 + 1) / 2 - (low + high) / 2 = (n1 + n2 + 1) / 2 - (n1) / 2 = (n2 +
            // 1) / 2 = half of n2 in first loop

            int l1 = INT_MIN, l2 = INT_MIN;
            int r1 = INT_MAX, r2 = INT_MAX;

            // Idea: treat the two arrays as one array, partition it to two parts to ensure every
            // thing on the left is smaller than everything on the right since mid1 and mid2 are
            // related, we can always ensure that they sum up to half of the total size when we exit
            // the loop, we find our target partition Determine values of l1, l2, r1, and r2

            if (mid1 < n1) r1 = nums1[mid1];
            if (mid2 < n2) r2 = nums2[mid2];
            if (mid1 - 1 >= 0) l1 = nums1[mid1 - 1];
            if (mid2 - 1 >= 0) l2 = nums2[mid2 - 1];
            // set up the values of l1, l2, r1, r2, if mid1 or mid2 is invalid, make them remain min/max

            if (l1 <= r2 && l2 <= r1) {
                // The partition is correct, we found the median
                // because we partitioned both arrays to two parts, all left is smaller than all
                // right, and size is half, so we can get the median
                if (n % 2 == 1)
                    return max(l1, l2);
                else
                    return ((double)(max(l1, l2) + min(r1, r2))) / 2.0;
            } else if (l1 > r2) {
                // Move towards the left side of nums1
                // because we exactly partition both array, if first array is too big, we need to
                // shrink it
                high = mid1 - 1;
            } else {
                // l2 > r1, means nums2 is too big, move low to mid makes mid1 bigger and mid2
                // smaller Move towards the right side of nums1
                low = mid1 + 1;
            }
        }

        return 0;  // If the code reaches here, the input arrays were not sorted.
    }
};
// @lc code=end
