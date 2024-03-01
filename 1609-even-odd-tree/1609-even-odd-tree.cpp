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
    bool isEvenOddTree(TreeNode* root) {
        if(!root) return true;
        queue<TreeNode*> pq;
        pq.push(root);
        bool even = true;

        while(!pq.empty()) {
            int n = pq.size();
            int preval = even ? INT_MIN : INT_MAX;
            for(int i = 0; i<n; i++) {
                TreeNode* t = pq.front();
                pq.pop();
                if(even && (t->val % 2 == 0 || preval >= t->val)) return false;
                if(!even && (t->val % 2 == 1 || preval <= t->val)) return false;
                preval = t->val;
                if(t->left) pq.push(t->left);
                if(t->right) pq.push(t->right);
            }
            even = !even;
        } 

        return true;
    }
};