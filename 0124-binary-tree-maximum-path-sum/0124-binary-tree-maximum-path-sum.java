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
    int findPath(TreeNode root, int[] maxPath) {
        if(root == null) return 0;

        int lpath = findPath(root.left, maxPath);
        int rpath = findPath(root.right, maxPath);

        int linePath = Math.max(Math.max(rpath, lpath) + root.val, root.val);
        int curvePath = Math.max(linePath, rpath + lpath + root.val);

        maxPath[0] = Math.max(curvePath, maxPath[0]);
        return linePath;
    }

    public int maxPathSum(TreeNode root) {
        int[] maxPath = new int[1];
        maxPath[0] = Integer.MIN_VALUE;
        findPath(root, maxPath);
        return maxPath[0];
    }
}