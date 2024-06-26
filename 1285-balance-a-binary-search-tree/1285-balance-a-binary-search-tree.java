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
    private void inorder(TreeNode root, List<TreeNode> list) {
        if(root == null) return;
        inorder(root.left, list);
        list.add(root);
        inorder(root.right, list);
    }

    private TreeNode balanceTree(int start, int end, List<TreeNode> list) {
        if(start > end) return null;
        int mid = (start + end)/2;
        TreeNode root = list.get(mid);
        root.left = balanceTree(start, mid - 1, list);
        root.right = balanceTree(mid + 1, end, list);
        return root;
    }

    public TreeNode balanceBST(TreeNode root) {
        List<TreeNode> nodeList = new ArrayList<>();
        inorder(root, nodeList);
        return balanceTree(0, nodeList.size() - 1, nodeList);
    }
}