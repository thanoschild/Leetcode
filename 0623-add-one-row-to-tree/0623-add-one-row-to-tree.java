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
    public TreeNode addOneRow(TreeNode root, int val, int depth) {
        if(depth == 1) {
            TreeNode newNode = new TreeNode(val);
            newNode.left = root;
            return newNode;
        }

        Queue<TreeNode> pq = new LinkedList<>();
        pq.add(root);
        int level = 0;
        boolean flag = false;

        while(!pq.isEmpty()) {
            int n = pq.size();
            level++;
            if(flag) break;

            for(int i = 0; i<n; i++) {
                TreeNode curr = pq.remove();

                if(level == depth - 1) {
                    flag = true;

                    TreeNode newNode1 = new TreeNode(val);
                    newNode1.left = curr.left;
                    curr.left = newNode1;

                    TreeNode newNode2 = new TreeNode(val);
                    newNode2.right = curr.right;
                    curr.right = newNode2;
                }
                else {
                    if(curr.left != null) pq.add(curr.left);
                    if(curr.right != null) pq.add(curr.right);
                }
            }
        }

        return root;
    }
}