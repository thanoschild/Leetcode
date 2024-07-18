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
    int ans = 0;
    vector<int> dfs(TreeNode* root, int d) {
        if(!root) return {};
        if(!root -> left && !root -> right) return {1};

        auto left = dfs(root -> left, d);
        auto right = dfs(root -> right, d);

        for(int x : left) {
            for(int y : right) {
                if(x + y <= d) ans++;
            }
        }

        vector<int> v;
        for(auto x : left) v.push_back(x+1);
        for(auto y : right) v.push_back(y + 1);

        return v;
    }
    
    int countPairs(TreeNode* root, int distance) {
        dfs(root, distance);
        return ans;
    }
};