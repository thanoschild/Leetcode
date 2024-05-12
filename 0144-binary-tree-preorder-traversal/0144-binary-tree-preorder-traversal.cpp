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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        TreeNode* curr;

        if(!root) return ans;

        while(root) {
            if(root -> left) {
                curr = root -> left;
                while(curr -> right && curr -> right != root) {
                    curr = curr -> right;
                }

                if(curr -> right) {
                    curr -> right = NULL;
                    root = root -> right;
                }
                else {
                    ans.push_back(root -> val);
                    curr -> right = root;
                    root = root -> left;
                }
            }
            else {
                ans.push_back(root -> val);
                root = root -> right;
            }
        }

        return ans;
    }
};