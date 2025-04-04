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
    private int height(TreeNode root) {
        if(root == null) return 0;
        int lh = height(root.left);
        int rh = height(root.right);
        return Math.max(lh, rh) + 1;
    }

    private TreeNode lca(TreeNode root) {
        if(root == null) return root;
        int lh = height(root.left);
        int rh = height(root.right);

        if(lh == rh) return root;
        if(lh > rh) return lca(root.left);
        return lca(root.right);
    }

    public TreeNode lcaDeepestLeaves(TreeNode root) {
        return lca(root);
    }
}