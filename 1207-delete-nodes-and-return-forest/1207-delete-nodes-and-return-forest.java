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
    private TreeNode dfs(TreeNode root, HashSet<Integer> st, List<TreeNode> ans) {
        if(root == null) return root;
        TreeNode l = dfs(root.left, st, ans);
        TreeNode r = dfs(root.right, st, ans);

        root.left = l;
        root.right = r;

        if(st.contains(root.val)) {
            if(root.left != null) ans.add(root.left);
            if(root.right != null) ans.add(root.right);

            return null;
        }

        return root;
    }

    public List<TreeNode> delNodes(TreeNode root, int[] to_delete) {
        List<TreeNode> ans = new ArrayList<>();
        HashSet<Integer> st = new HashSet<>();
        for(int n : to_delete) st.add(n);

        root = dfs(root, st, ans);
        if(root != null) ans.add(root);

        return ans;
    }
}