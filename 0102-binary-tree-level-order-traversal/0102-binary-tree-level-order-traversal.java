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
    public List<List<Integer>> levelOrder(TreeNode root) {
        List<List<Integer>> ans = new ArrayList<>();
        if(root == null) return ans;

        Queue<TreeNode> pq = new LinkedList<>();
        pq.add(root);

        while(!pq.isEmpty()) {
            int n = pq.size();
            List<Integer> curr = new ArrayList<>();

            for(int i = 0; i<n; i++) {
                TreeNode t = pq.poll();

                curr.add(t.val);
                if(t.left != null) pq.add(t.left);
                if(t.right != null) pq.add(t.right);
            }

            ans.add(curr);
        }

        return ans;
    }
}