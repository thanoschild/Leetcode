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
    void solve(TreeNode* root, string curr, string &ans) {
        if(!root) return;
        curr = (char)('a' + root->val) + curr;
        if(!root->left && !root->right) {
           if(ans == "") ans = curr;
           else if(ans > curr) ans = curr;
        }

        solve(root->left, curr, ans);
        solve(root->right, curr, ans);
    }

    string smallestFromLeaf(TreeNode* root) {
        if(!root) return "";
        string ans = "";
        solve(root, "", ans);
        return ans;
    }
};