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
    
    private int solve(TreeNode root, int mx, int mn) {
        if(root == null) return mx - mn;
        mx = Math.max(mx, root.val);
        mn = Math.min(mn, root.val);

        int x = solve(root.left, mx, mn);
        int y = solve(root.right, mx, mn);

        return Math.max(x, y);
    }

    public int maxAncestorDiff(TreeNode root) {
        return solve(root, root.val, root.val);
    }
}