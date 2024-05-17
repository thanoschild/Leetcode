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
    int solve(TreeNode* root, int target) {
        if(!root) return -1;
        int l = solve(root -> left, target);
        if(l == -1) root -> left = NULL;
        int r = solve(root -> right, target);
        if(r == -1) root -> right = NULL;

        if(l == -1 && r == -1 && root -> val == target) return -1;
        return 0;
    }
    
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        int ans = solve(root, target);
        return ans == -1 ? NULL : root;
    }
};