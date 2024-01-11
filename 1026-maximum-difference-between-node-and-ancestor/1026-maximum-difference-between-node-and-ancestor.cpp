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
   
    int solve(TreeNode* root, int mx, int mn) {
        if(!root) return mx - mn;
        mx = max(mx, root->val);
        mn = min(mn, root->val);
        
        int x = solve(root->left, mx, mn);
        int y = solve(root->right, mx, mn);

        return max(x, y);
    }

    int maxAncestorDiff(TreeNode* root) {
        return solve(root, root->val, root->val);
    }
};