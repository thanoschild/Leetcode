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
    public long kthLargestLevelSum(TreeNode root, int k) {
        PriorityQueue<Long> pq = new PriorityQueue<>();
        Queue<TreeNode> q = new LinkedList<>();
        q.add(root);

        while(!q.isEmpty()) {
            int n = q.size();
            long sum = 0;
            for(int i = 0; i<n; i++) {
                TreeNode t = q.poll();
                sum += t.val;

                if(t.left != null) q.add(t.left);
                if(t.right != null) q.add(t.right);
            }
            
            pq.add(sum);
            if(pq.size() > k) pq.poll();
        }

        if(pq.size() < k) return -1;
        return pq.peek();
    }
}