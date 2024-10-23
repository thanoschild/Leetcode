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
    TreeNode* replaceValueInTree(TreeNode* root) {
        if(!root) return root;
        root -> val = 0;
        queue<TreeNode*> pq;
        pq.push(root);

        while(!pq.empty()) {
            int n = pq.size();
            int sum = 0;
            vector<TreeNode*> prev;
            for(int i = 0; i<n; i++) {
                TreeNode* node = pq.front();
                pq.pop();
                prev.push_back(node);

                if(node -> left) {
                    pq.push(node -> left);
                    sum += node -> left -> val;
                }
                if(node -> right) {
                    pq.push(node -> right);
                    sum += node -> right -> val;
                }
            }

            for(TreeNode* node : prev) {
                int t = sum;
                if(node -> left) t -= node -> left -> val;
                if(node -> right) t -= node -> right -> val;
                if(node -> left) node -> left -> val = t;
                if(node -> right) node -> right -> val = t;
            }
        }

        return root;
    }
};