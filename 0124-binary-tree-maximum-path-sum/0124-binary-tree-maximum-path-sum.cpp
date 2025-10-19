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
    int findPath(TreeNode* root, int &maxPath) {
        if(!root) return 0;

        int lpath = findPath(root->left, maxPath);
        int rpath = findPath(root->right, maxPath);

        int linePath = max(max(lpath, rpath) + root->val, root->val);
        int curvePath = max(linePath, lpath + rpath + root->val);

        maxPath = max(curvePath, maxPath);
        return linePath;
    }

    int maxPathSum(TreeNode* root) {
        int maxPath = INT_MIN;
        findPath(root, maxPath);
        return maxPath;
    }
};