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
    List<Integer> dfs(TreeNode root, int d) {
        List<Integer> v = new ArrayList<>();
        if(root == null) return v;
        if(root.left == null && root.right == null) {
            v.add(1);
            return v;
        }

        List<Integer> left = dfs(root.left, d);
        List<Integer> right = dfs(root.right, d);

        for(int x : left) {
            for(int y : right) {
                if(x + y <= d) ans++;
            }
        }

        for(int x : left) v.add(x + 1);
        for(int x : right) v.add(x + 1);

        return v;
    }
    
    public int countPairs(TreeNode root, int distance) {
        ans = 0;
        dfs(root, distance);
        return ans;
    }
}