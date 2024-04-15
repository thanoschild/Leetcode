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
    void solve(TreeNode* root, int curr, int &sum) {
        if(!root) return;
        curr = curr*10 + root->val;
        if(!root->left && !root->right) {
            sum += curr;
        }

        solve(root->left, curr, sum);
        solve(root->right, curr, sum);
    }
    
    int sumNumbers(TreeNode* root) {
        if(!root) return 0;
        int sum = 0;
        solve(root, 0, sum);
        return sum;
    }
};