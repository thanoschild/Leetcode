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
    TreeNode* dfs(TreeNode* root, set<int> &st, vector<TreeNode*> &ans) {
        if(!root) return NULL;

        TreeNode* l = dfs(root -> left, st, ans);
        TreeNode* r = dfs(root -> right, st, ans);

        root -> left = l;
        root -> right = r;

        if(st.find(root -> val) != st.end()) {
            if(root -> left) ans.push_back(root -> left);
            if(root -> right) ans.push_back(root -> right);
            delete root;
            return NULL;
        }

        return root;
    }
    
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> ans;
        set<int> st(to_delete.begin(), to_delete.end());

        root = dfs(root, st, ans);
        if(root) ans.push_back(root);

        return ans;
    }
};