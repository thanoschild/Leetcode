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
    private int solve(TreeNode root, int target) {
        if(root == null) return -1;
        int l = solve(root.left, target);
        if(l == -1) root.left = null;
        int r = solve(root.right, target);
        if(r == -1) root.right = null;

        if(l == -1 && r == -1 && root.val == target) {
            return -1;
        }

        return 0;
    }

    public TreeNode removeLeafNodes(TreeNode root, int target) {
        int ans = solve(root, target);
        return ans == -1 ? null : root;
    }
}