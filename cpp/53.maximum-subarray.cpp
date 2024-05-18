/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 */

// @lc code=start

#include <climits>
#include <vector>
#include <algorithm>
using namespace std;

// class Solution {
// public:
//     int maxSubArray(vector<int>& nums) {
//         // Idea: dp of 1D vector
//         // subproblem dp[i] store the maximum sum of subarray ending with
//         nums[i]
//         // original problem dp[nums.size() - 1]
//         // formula dp[i] = max(dp[i - 1] + nums[i], nums[i])

//         int size = nums.size();
//         int max_sum = nums[0];
//         int current_sum = nums[0];

//         for (int i = 1; i < size; i++) {
//             current_sum = max(current_sum + nums[i], nums[i]);
//             max_sum = max(max_sum, current_sum);
//         }

//         return max_sum;
//     }
// };

class Solution {
   public:
    int maxSubArray(vector<int>& nums) {
        // Second Idea: divide and conquer
        return maxSubArray(nums, 0, size(nums) - 1);
    }

    // helper function to find max subarray sum in [L, R]
    int maxSubArray(vector<int>& A, int L, int R) {
        // If L > R, it means the subarray is empty 
        // because the case of maxSubArray(A, L, mid - 1) will return 0 and case of all negative values
        if (L > R) return INT_MIN;

        // Init variables
        int mid = (L + R) / 2;

        // Note: we first calculate leftSum and rightSum, which are the max 
        //  subarray sum in [L, mid-1] and [mid+1, R] both include mid (start
        //  from mid-1 and mid+1 respectively)

        // leftSum = max subarray sum in [L, mid-1] and starting from mid-1
        // Note: it must starting from mid-1, so the algorithm will work
        int leftSum = 0;
        int curSum = 0;
        for (int i = mid - 1; i >= L; i--) {
            curSum += A[i];
            leftSum = max(leftSum, curSum);
        }

        // rightSum = max subarray sum in [mid+1, R] and starting from mid+1
        int rightSum = 0;
        curSum = 0;
        for (int i = mid + 1; i <= R; i++) {
            curSum += A[i];
            rightSum = max(rightSum, curSum);
        }

        // return max of 3 cases
        // case 1: max subarray in [L, R] is in left part, don't include mid, so
        //  we use maxSubArray(A, L, mid - 1)
        // case 2: max subarray in [L, R] is in right part, don't include mid,
        //  so we use maxSubArray(A, mid + 1, R)
        // case 3: max subarray include mid,
        //  so we use leftSum + A[mid] + rightSum
        return max({maxSubArray(A, L, mid - 1), maxSubArray(A, mid + 1, R),
                    leftSum + A[mid] + rightSum});
    }
};
// @lc code=end
