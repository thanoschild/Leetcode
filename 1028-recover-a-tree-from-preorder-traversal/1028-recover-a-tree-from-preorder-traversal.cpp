/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* recoverFromPreorder(string s) {
        vector<TreeNode*> st;
        
        for(int i = 0; i<s.size();) {
            int level, val;
            for(level = 0; s[i] == '-'; i++) level++;
            for(val = 0; i < s.size() && s[i] != '-'; i++) val = val*10 + (s[i] - '0');
            while(st.size() > level) st.pop_back();

            TreeNode* node = new TreeNode(val);
            if(!st.empty()) {
                if(!st.back()->left) st.back()->left = node;
                else st.back()->right = node;
            }
            st.push_back(node);
        }

        return st[0];
    }
};