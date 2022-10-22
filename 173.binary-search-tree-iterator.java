/*
 * @lc app=leetcode id=173 lang=java
 *
 * [173] Binary Search Tree Iterator
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */

class BSTIterator {
    // 模拟递归栈
    // a stack with element type treenode
    private Stack<TreeNode> stk = new Stack<>();

    // 左侧树枝一撸到底
    private void pushLeftBranch(TreeNode p) {
        while (p != null) {
            stk.push(p);
            p = p.left;
        }
    }

    // start here, push everything to the stack
    public BSTIterator(TreeNode root) {
        pushLeftBranch(root);
    }
    
    // since it's a stack, top is smallest
    public int next() {
        TreeNode p = stk.pop();
        // push right branches everything to the stack
        pushLeftBranch(p.right);
        return p.val;
    }
    
    // if the stack is empty, then nothing left, return false
    public boolean hasNext() {
        return !stk.isEmpty();
    }
}

// class BSTIterator {
//     // use list to store
//     List<Integer> list= new ArrayList<>();
//     int index=0;

//     public BSTIterator(TreeNode root) {
//         inorder(root);
        
//     }
//     // do in_order traversal of the tree
//     void inorder(TreeNode root){
//         if(root==null) return;
//         // add everything to the list
//         inorder(root.left);
//         list.add(root.val);
//         inorder(root.right);
//     }

//     public int next() {
//         return list.get(index++);
//     }
    
//     public boolean hasNext() {
//         return index<list.size();
//     }
// }


/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator obj = new BSTIterator(root);
 * int param_1 = obj.next();
 * boolean param_2 = obj.hasNext();
 */
// @lc code=end

