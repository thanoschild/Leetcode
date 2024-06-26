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
    vector<TreeNode*> nodeArr;

    void inorder(TreeNode* root) {
        if(!root) return;
        inorder(root->left);
        nodeArr.push_back(root);
        inorder(root->right);
    }

    TreeNode* makeBalanceTree(int start, int end) {
        if(start > end) return NULL;
        int mid = (start + end)/2;
        TreeNode* root = nodeArr[mid];
        root->left = makeBalanceTree(start, mid - 1);
        root->right = makeBalanceTree(mid+1, end);
        return root;
    }

    TreeNode* balanceBST(TreeNode* root) {
        inorder(root);
        return makeBalanceTree(0, nodeArr.size() - 1);
    }
};