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
    public boolean isEvenOddTree(TreeNode root) {
        if(root == null) return true;
        Queue<TreeNode> pq = new LinkedList<>();
        pq.add(root);
        boolean even = true;

        while(!pq.isEmpty()) {
            int n = pq.size();
            int preval = even ? Integer.MIN_VALUE : Integer.MAX_VALUE;
            for(int i = 0; i<n; i++) {
                TreeNode t = pq.poll();
                if(even && (t.val % 2 == 0 || preval >= t.val)) return false;
                if(!even && (t.val % 2 == 1 || preval <= t.val)) return false;
                preval = t.val;
                if(t.left != null) pq.add(t.left);
                if(t.right != null) pq.add(t.right);
            }
            even = !even;
        } 

        return true;
    }
}