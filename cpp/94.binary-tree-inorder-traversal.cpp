/*
 * @lc app=leetcode id=94 lang=cpp
 *
 * [94] Binary Tree Inorder Traversal
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

// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };

#include <vector>
using namespace std;
class Solution {
   public:
    vector<int> inorderTraversal(TreeNode *root) {
        // Note: Inorder traversal is left -> root -> right
        // i.e.: from smallest to largest
        vector<int> result;
        inorder_helper(root, result);
        return result;
    }

    void inorder_helper(TreeNode *root, vector<int> &result) {
        if (root == nullptr) {
            return;
        }
        // left first
        inorder_helper(root->left, result);
        // root
        result.push_back(root->val);
        // last right
        inorder_helper(root->right, result);
    }
};
// @lc code=end
