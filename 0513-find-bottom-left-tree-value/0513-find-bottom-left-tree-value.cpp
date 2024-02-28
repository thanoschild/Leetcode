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
    void solve(TreeNode* root, int &ans, int &mx_lev, int lev) {
        if(!root) return;
        if(lev > mx_lev) {
            ans = root->val;
            mx_lev = lev;
        }
        solve(root->left, ans, mx_lev, lev+1);
        solve(root->right, ans, mx_lev, lev+1);
    }

    int findBottomLeftValue(TreeNode* root) {
        int ans = 0, mx_lev = 0, lev = 0;
        if(!root->left && !root->right) return root->val;
        solve(root, ans, mx_lev, lev);
        return ans;
    }
};