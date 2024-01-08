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
class Solution {
    int sum;
    public void solve(TreeNode root, int low, int high) {
        if(root == null) return;
        solve(root.left, low, high);
        if(root.val >= low && root.val <= high) sum += root.val;
        solve(root.right, low, high);
    }

    public int rangeSumBST(TreeNode root, int low, int high) {
        sum = 0;
        solve(root, low, high);
        return sum;
    }
}