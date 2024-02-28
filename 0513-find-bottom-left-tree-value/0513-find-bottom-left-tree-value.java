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
    public int findBottomLeftValue(TreeNode root) {
        if(root == null) return -1;
        Queue<TreeNode> pq = new LinkedList<>();
        pq.add(root);
        int ans = -1;

        while(!pq.isEmpty()) {
            int n = pq.size();
            for(int i = 0; i<n; i++) {
                TreeNode t = pq.poll();
                if(i == 0) ans = t.val;

                if(t.left != null) pq.add(t.left);
                if(t.right != null) pq.add(t.right);
            }
        }

        return ans;
    }
}