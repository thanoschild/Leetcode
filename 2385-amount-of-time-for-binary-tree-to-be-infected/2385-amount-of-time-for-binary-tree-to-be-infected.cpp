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
    int ans;

    int dfs(TreeNode* root, int start) {
        if(!root) return 0;

        int x = dfs(root->left, start);
        int y = dfs(root->right, start);

        if(root->val == start) {
            ans = max(ans, max(x, y));
            return -1;
        }

        if(x >= 0 && y >= 0) return max(x, y) + 1;
        ans = max(ans, abs(x) + abs(y));

        return min(x, y) - 1;
    }

    int amountOfTime(TreeNode* root, int start) {
        ans = 0;
        dfs(root, start);
        return ans;
    }
};