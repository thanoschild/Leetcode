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

    public void solve(TreeNode root, StringBuilder curr, StringBuilder ans) {
        if (root == null) return;
        curr.insert(0, (char) ('a' + root.val));
        if (root.left == null && root.right == null) {
            if (ans.length() == 0) ans.append(curr);
            else if (ans.toString().compareTo(curr.toString()) > 0) ans.replace(0, ans.length(), curr.toString());
        }

        solve(root.left, curr, ans);
        solve(root.right, curr, ans);
        curr.deleteCharAt(0);
    }

    public String smallestFromLeaf(TreeNode root) {
        if (root == null) return "";
        StringBuilder ans = new StringBuilder();
        solve(root, new StringBuilder(), ans);
        return ans.toString();
    }
}