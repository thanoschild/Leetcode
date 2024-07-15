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
    public TreeNode createBinaryTree(int[][] arr) {
        HashMap<Integer, TreeNode> map = new HashMap<>();
        HashSet<Integer> st = new HashSet<>();

        for(int[] it : arr) {
            if(!map.containsKey(it[0])) map.put(it[0], new TreeNode(it[0]));
            if(!map.containsKey(it[1])) map.put(it[1], new TreeNode(it[1]));

            if(it[2] == 1) map.get(it[0]).left = map.get(it[1]);
            else map.get(it[0]).right = map.get(it[1]);
            st.add(it[1]);
        }

        for(int[] it : arr) {
            if(!st.contains(it[0])) return map.get(it[0]);
        }

        return null;
    }
}