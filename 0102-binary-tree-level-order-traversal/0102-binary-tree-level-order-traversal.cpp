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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;

        queue<TreeNode*> pq;
        pq.push(root);
        
        while(!pq.empty()) {
            int n = pq.size();
            vector<int> curr;

            for(int i = 0; i<n; i++) {
                TreeNode* t = pq.front();
                pq.pop();

                curr.push_back(t -> val);
                if(t -> left) pq.push(t -> left);
                if(t -> right) pq.push(t -> right);
            }

            ans.push_back(curr);
        }

        return ans;
    }
};