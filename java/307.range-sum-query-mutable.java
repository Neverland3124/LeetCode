/*
 * @lc app=leetcode id=307 lang=java
 *
 * [307] Range Sum Query - Mutable
 */

// @lc code=start
// segmented tree && bit tree && Sqrt Decomposition

// Sqrt Decomposition
// class NumArray {
//     // block
//     private int len;
//     private int[] b;
//     private int[] nums;

//     // constructor
//     public NumArray(int[] nums) {
//         this.nums = nums;
//         // find len of the block array
//         double l = Math.sqrt(nums.length);
//         len = (int) Math.ceil(nums.length/l);
//         b = new int [len];
//         // update block
//         for (int i = 0; i < nums.length; i++)
//             b[i / len] += nums[i];
//     }

//     public int sumRange(int i, int j) {
//         int sum = 0;
//         int startBlock = i / len;
//         int endBlock = j / len;
//         if (startBlock == endBlock) {
//             // same block, constant time
//             for (int k = i; k <= j; k++)
//             sum += nums[k];
//         } else {
//             // loop over block to let i = j
//             // sum the number in the i block
//             for (int k = i; k <= (startBlock + 1) * len - 1; k++)
//                 sum += nums[k];
//             for (int k = startBlock + 1; k <= endBlock - 1; k++)
//                 sum += b[k];
//             // j block
//             for (int k = endBlock * len; k <= j; k++)
//                 sum += nums[k];
//         }
//         return sum;
//     }

//     public void update(int i, int val) {
//         int b_l = i / len;
//         // update the block value
//         b[b_l] = b[b_l] - nums[i] + val;
//         nums[i] = val;
//     }
// }

// bit tree: https://cs.stackexchange.com/questions/10538/bit-what-is-the-intuition-behind-a-binary-indexed-tree-and-how-was-it-thought-a
// public class NumArray {
//     int[] arr; // stores nums[]
//     int[] BITree; // binary indexed tree

//     public NumArray(int[] nums) {
//         // init
//         int n = nums.length;
//         arr = new int[n];
//         BITree = new int[n + 1];

//         // init bit and arr
//         for (int i = 0; i < n; i++) {
//             update(i, nums[i]); // init BITree[]
//         }
//     }

//     // update arr value and bit value
//     void update(int i, int val) {
//         // need diff value from the array to update bitree
//         int diff = val - arr[i]; // get the diff
//         arr[i] = val; // update arr[]

//         i++;
//         // while loop to update all left side of the tree

//         while (i <= arr.length) {
//             BITree[i] += diff; // update BITree[]
//             // i & (~i + 1) is a trick to extract the lowest set bit of i
//             // i & (-i) get the last one, i += i += i & (-i) go to next bit in the array
//             // 1 -> 2 -> 4 -> 8
//             i += i & (-i); // update index to that of parent
//         }
//     }
//     // given the position, find sum of 1 +++ i
//     int getSum(int i) {
//         int sum = 0;
//         // index in bit tree need to + 1
//         i++;
//         while (i > 0) {
//             // end when i = 0, reach root
//             sum += BITree[i]; // accumulate the sum
//             // git rid of all 1's
//             // 6 -> 4 -> 0 since 4 will store 1 to 4
//             i -= i & (-i); // move index to parent node
//         }
//         return sum;
//     }

//     public int sumRange(int i, int j) {
//         // sum range is call get sum twice
//         return getSum(j) - getSum(i - 1);
//     }
// }

// segment tree
class NumArray {
    SegmentTree segmentTree;
    int n;

    public NumArray(int[] nums) {
        n = nums.length;
        segmentTree = new SegmentTree(nums);
    }

    public void update(int index, int val) {
        segmentTree.update(0, 0, n - 1, index, val);
    }

    public int sumRange(int left, int right) {
        return segmentTree.getSum(0, 0, n - 1, left, right);
    }
}

class SegmentTree {
    int[] tree;
    int n;
    int[] nums;

    public SegmentTree(int[] nums) {
        this.nums = nums;
        n = nums.length;
        // reason for 4 * n
        // https://cp-algorithms.com/data_structures/segment_tree.html#structure-of-the-segment-tree
        tree = new int[4 * n];
        buildTree(0, 0, n - 1);
    }

    private void buildTree(int treeIndex, int l, int r) {
        // base case, two of them
        if (l == r) {
            tree[treeIndex] = nums[l];
            return;
        }
        int mid = (l + r) / 2;

        // left subtree [x, 2x + 1]
        // 1 3 4 7 8 9 10
        int leftChildIndex = 2 * treeIndex + 1;
        buildTree(leftChildIndex, l, mid);

        // right subtree
        // 2 5 6 11 12 13 14
        int rightChildIndex = 2 * treeIndex + 2;
        buildTree(rightChildIndex, mid + 1, r);

        // save the sum of both child
        tree[treeIndex] = tree[leftChildIndex] + tree[rightChildIndex];
    }

    public int getSum(int treeIndex, int l, int r, int i, int j) {
        if (l > j || r < i)
            return 0;
        if (l >= i && r <= j)
            return tree[treeIndex];

        int mid = (l + r) / 2;
        int leftChildIndex = 2 * treeIndex + 1;
        int rightChildIndex = 2 * treeIndex + 2;

        if (j <= mid) {
            // As required range will be first half (left subtree)
            // just check the first half
            return getSum(leftChildIndex, l, mid, i, j);
        } else if (i > mid) {
            // As required range will be 2nd half (right subtree)
            // just check the 2nd half only
            return getSum(rightChildIndex, mid + 1, r, i, j);
        }
        // i mid j
        return getSum(leftChildIndex, l, mid, i, mid) + getSum(rightChildIndex, mid + 1, r, mid + 1, j);
    }

    public void update(int treeIndex, int l, int r, int index, int val) {
        if (l == r) {
            // new value
            tree[treeIndex] = val;
            return;
        }
        int mid = (l + r) / 2;
        int leftChildIndex = 2 * treeIndex + 1;
        int rightChildIndex = 2 * treeIndex + 2;
        if (index <= mid) {
            update(leftChildIndex, l, mid, index, val);
        } else if (index > mid) {
            update(rightChildIndex, mid + 1, r, index, val);
        }
        // re cal the value
        tree[treeIndex] = tree[leftChildIndex] + tree[rightChildIndex];
    }
}
/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(index,val);
 * int param_2 = obj.sumRange(left,right);
 */
// @lc code=end
