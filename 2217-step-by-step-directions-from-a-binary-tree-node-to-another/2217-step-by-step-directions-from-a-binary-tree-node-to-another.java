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
    public TreeNode getLca(TreeNode root, int start, int dest) {
        if (root == null) return null;
        if (root.val == start || root.val == dest) return root;

        TreeNode left = getLca(root.left, start, dest);
        TreeNode right = getLca(root.right, start, dest);

        if (left != null && right != null) return root;

        return left != null ? left : right;
    }

    public boolean traverseTree(TreeNode root, int target, StringBuilder s) {
        if (root == null) return false;
        if (root.val == target) return true;

        s.append('L');
        if (traverseTree(root.left, target, s)) return true;
        s.deleteCharAt(s.length() - 1);

        s.append('R');
        if (traverseTree(root.right, target, s)) return true;
        s.deleteCharAt(s.length() - 1);

        return false;
    }

    public String getDirections(TreeNode root, int start, int dest) {
        TreeNode lca = getLca(root, start, dest);

        StringBuilder s = new StringBuilder();
        StringBuilder d = new StringBuilder();
        traverseTree(lca, start, s);
        traverseTree(lca, dest, d);
        
        for (int i = 0; i < s.length(); i++) {
            s.setCharAt(i, 'U');
        }
        return s.toString() + d.toString();
    }
}