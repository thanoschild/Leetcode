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

    void solve(TreeNode root, List<Integer> ans) {
        if(root == null) return;
        solve(root.left, ans);
        if(root.left == null && root.right == null) ans.add(root.val);
        solve(root.right, ans);
    }

    public boolean leafSimilar(TreeNode root1, TreeNode root2) {
        List<Integer> ans1 = new ArrayList<>();
        List<Integer> ans2 = new ArrayList<>();

        solve(root1, ans1);
        solve(root2, ans2);

        if(ans1.size() != ans2.size()) return false;
        for(int i = 0; i<ans1.size(); i++) {
            if(ans1.get(i) != ans2.get(i)) return false;
        }

        return true;
    }
}