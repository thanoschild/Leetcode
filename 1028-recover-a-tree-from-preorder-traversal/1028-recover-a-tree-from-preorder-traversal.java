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
    public TreeNode recoverFromPreorder(String s) {
        Stack<TreeNode> st = new Stack<>();
        for(int i = 0; i<s.length();) {
            int level, val;
            for(level = 0; s.charAt(i) == '-'; i++) level++;
            for(val = 0; i < s.length() && s.charAt(i) != '-'; i++) val = val*10 + (s.charAt(i) - '0');
            while(st.size() > level) st.pop();

            TreeNode node = new TreeNode(val);
            if(!st.isEmpty()) {
                if(st.peek().left == null) st.peek().left = node;
                else st.peek().right = node;
            }
            st.add(node);
        }

        while(st.size() > 1) st.pop();
        return st.peek();
    }
}