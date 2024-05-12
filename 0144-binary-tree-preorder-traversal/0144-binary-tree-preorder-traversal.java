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
    public List<Integer> preorderTraversal(TreeNode root) {
        List<Integer> ans = new ArrayList<>();
        if(root == null) return ans;
        TreeNode curr;

        while(root != null) {
            if(root.left != null) {
                curr = root.left;
                while(curr.right != null && curr.right != root) {
                    curr = curr.right;
                }

                if(curr.right == null) {
                    ans.add(root.val);
                    curr.right = root;
                    root = root.left;
                }
                else {
                    curr.right = null;
                    root = root.right;
                }
            }
            else {
                ans.add(root.val);
                root = root.right;
            }
        }

        return ans;
    }
}