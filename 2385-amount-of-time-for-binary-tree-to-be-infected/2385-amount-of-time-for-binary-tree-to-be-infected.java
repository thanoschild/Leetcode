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
    int ans;

    int dfs(TreeNode root, int start) {
        if(root == null) return 0;

        int x = dfs(root.left, start);
        int y = dfs(root.right, start);

        if(root.val == start) {
            ans = Math.max(ans, Math.max(x, y));
            return -1;
        }

        if(x >= 0 && y >= 0) return Math.max(x, y) + 1;
        ans = Math.max(ans, Math.abs(x) + Math.abs(y));

        return Math.min(x, y) - 1; 
    }

    public int amountOfTime(TreeNode root, int start) {
        ans = 0;
        dfs(root, start);
        return ans;
    }
}