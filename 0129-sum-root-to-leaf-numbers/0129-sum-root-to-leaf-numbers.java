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
    private void solve(TreeNode root, int curr, int[] sum) {
        if(root == null) return;
        curr = curr * 10 + root.val;
        if(root.left == null && root.right == null) {
            sum[0] += curr;
        }

        solve(root.left, curr, sum);
        solve(root.right, curr, sum);
    }

    public int sumNumbers(TreeNode root) {
        if(root == null) return 0;
        int[] sum = new int[1];
        solve(root, 0, sum);
        return sum[0];
    }
}