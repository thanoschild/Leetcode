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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1) {
            TreeNode* new_node = new TreeNode(val);
            new_node->left = root;
            return new_node;
        }

        queue<TreeNode*> pq;
        pq.push(root);
        int level = 0;
        bool flag = false;

        while(!pq.empty()) {
            int n = pq.size();
            level += 1;
            if(flag) break;

            for(int i = 0; i<n; i++) {
                TreeNode* curr = pq.front();
                pq.pop();

                if(level == depth - 1) {
                    flag = true;
                    
                    TreeNode* new_node1 = new TreeNode(val);
                    new_node1->left = curr->left;
                    curr->left = new_node1;

                    TreeNode* new_node2 = new TreeNode(val);
                    new_node2->right = curr->right;
                    curr->right = new_node2;
                }
                else {
                    if(curr->left) pq.push(curr->left);
                    if(curr->right) pq.push(curr->right);
                }
            }
        }

        return root;
    }
};