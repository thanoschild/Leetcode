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
    private int postOrder(TreeNode root, int[] moves) {
        if(root == null) return 0;
        int l = postOrder(root.left, moves);
        int r = postOrder(root.right, moves);
        moves[0] += Math.abs(l) + Math.abs(r);
        return root.val + l + r - 1;
    }

    public int distributeCoins(TreeNode root) {
        int[] moves = new int[1];
        postOrder(root, moves);
        return moves[0];
    }
}