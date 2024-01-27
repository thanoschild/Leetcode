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
    HashMap<Integer, Integer> map = new HashMap<>();
    int ans;

    public void solve(TreeNode root) {
        if(root == null) return;
        map.put(root.val, map.getOrDefault(root.val, 0) + 1);

        if(root.left == null && root.right == null) {
            int odd = 0;
            for(int it : map.values()) {
                if(it % 2 == 1) odd++;
            }
            if(odd <= 1) ans++;
        }

        solve(root.left);
        solve(root.right);
        map.put(root.val, map.getOrDefault(root.val, 0) - 1);
    }

    public int pseudoPalindromicPaths (TreeNode root) {
        ans = 0;
        solve(root);
        return ans;
    }
}