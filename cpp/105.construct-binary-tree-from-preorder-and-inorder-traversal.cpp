/*
 * @lc app=leetcode id=105 lang=cpp
 *
 * [105] Construct Binary Tree from Preorder and Inorder Traversal
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#include <map>
#include <vector>
using namespace std;

class Solution {
   public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        int preStart = 0, preEnd = preorder.size() - 1;
        int inStart = 0, inEnd = inorder.size() - 1;

        map<int, int> mp;
        // the key is the element from the inorder vector and the value is the index of that
        // element.
        // example: inorder = [9,3,15,20,7]
        // mp[9] = 0, mp[3] = 1, mp[15] = 2, mp[20] = 3, mp[7] = 4
        for (int i = inStart; i <= inEnd; i++) {
            mp[inorder[i]] = i;
        }

        // then call the helper constructTree function
        return constructTree(preorder, inorder, mp, preStart, preEnd, inStart, inEnd);
    }

    TreeNode *constructTree(vector<int> &preorder, vector<int> &inorder, map<int, int> &mp,
                            int preStart, int preEnd, int inStart, int inEnd) {
        // If pre or in start reaches the end, return NULL
        // represent no elements in the leaf
        if (preStart > preEnd || inStart > inEnd) return NULL;

        // the root node is the first element in the preorder vector
        TreeNode *root = new TreeNode(preorder[preStart]);

        // find the index of the root node in the inorder vector
        // example: mp[3] = 1 = elem, nElem = 1 - 0 = 1
        // elem represents the index of the inorder vector where the root node is located, what's
        // before elem is the left subtree, what's after elem is the right subtree
        int elem = mp[root->val];
        int nElem = elem - inStart;

        // Note: preStart + 1 because the first is root
        // inStart doesn't change, elem is the root, so elem - 1 is the end of the left subtree
        root->left =
            constructTree(preorder, inorder, mp, preStart + 1, preStart + nElem, inStart, elem - 1);
        // Note: preStart + 1 + nElem because the first is root, nElem is the number of elements in
        // the left subtree intEnd doesn't change, elem is the root, so elem + 1 is the start of the
        // right subtree
        root->right =
            constructTree(preorder, inorder, mp, preStart + 1 + nElem, preEnd, elem + 1, inEnd);

        return root;

        // Note: the biggest thing is that in preorder, the divide of left and right is root +
        // number of elements in the left subtree, which we can get from the location of root at the
        // inorder array, what's on the left of the position is the number of elements in the left
        // subtree

        // example: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
        // Output: [3,9,20,null,null,15,7]
        // first root: 3
        // elem = 1, nElem = 1
        // left subtree for preorder: [9], right: [20,15,7]
        // left subtree for inorder: [9], right: [15,20,7]
    }
};
// @lc code=end
