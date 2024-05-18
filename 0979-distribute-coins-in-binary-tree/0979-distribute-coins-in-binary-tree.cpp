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
    int postOrder(TreeNode* root, int &moves) {
        if(!root) return 0;
        int l = postOrder(root -> left, moves);
        int r = postOrder(root -> right, moves);
        moves += abs(l) + abs(r);
        return root -> val + l + r - 1;
    }
    int distributeCoins(TreeNode* root) {
        int moves = 0;
        postOrder(root, moves);
        return moves;
    }
};