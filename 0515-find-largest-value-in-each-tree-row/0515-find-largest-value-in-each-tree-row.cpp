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
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        if(!root) return ans;

        queue<TreeNode*> pq;
        pq.push(root);
        
        while(!pq.empty()) {
            int n = pq.size();
            int maxval = INT_MIN;
            for(int i = 0; i<n; i++) {
                TreeNode* t = pq.front();
                pq.pop();
                maxval = max(maxval, t->val);

                if(t->left) pq.push(t->left);
                if(t->right) pq.push(t->right);
            }
            ans.push_back(maxval);
        }

        return ans;
    }
};