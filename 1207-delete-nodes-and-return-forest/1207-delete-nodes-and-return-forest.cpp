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
    void solve(TreeNode* root, TreeNode* parent, bool isLeft, set<int> &st, vector<TreeNode*> &ans) {
        if(!root) return;

        solve(root -> left, root, true, st, ans);
        solve(root -> right, root, false, st, ans);

        if(st.find(root -> val) != st.end()) {
            if(root -> left) ans.push_back(root -> left);
            if(root -> right) ans.push_back(root -> right);

            if(parent) {
                if(isLeft) parent -> left = NULL;
                else parent -> right = NULL;
            }
            else root = NULL;
            delete root;
            return;
        }
    }
    
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> ans;
        set<int> st(to_delete.begin(), to_delete.end());

        solve(root, NULL, false, st, ans);
        if(root && st.find(root -> val) == st.end()) ans.push_back(root);

        return ans;
    }
};