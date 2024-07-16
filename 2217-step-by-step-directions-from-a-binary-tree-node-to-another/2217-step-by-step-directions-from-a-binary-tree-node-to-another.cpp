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
    TreeNode* getLca(TreeNode* root, int start, int dest) {
        if(!root) return NULL;
        if(root -> val == start || root -> val == dest) return root;

        TreeNode* l = getLca(root -> left, start, dest);
        TreeNode* r = getLca(root -> right, start, dest);

        if(l && r) return root;

        return l ? l : r;
    }

    bool traverseTree(TreeNode* root, int target, string &s) {
        if(!root) return false;
        if(root -> val == target) return true;

        s.push_back('L');
        if(traverseTree(root -> left, target, s)) return true;
        s.pop_back();

        s.push_back('R');
        if(traverseTree(root -> right, target, s)) return true;
        s.pop_back();

        return false;
    }

    string getDirections(TreeNode* root, int start, int dest) {
        TreeNode* lca = getLca(root, start, dest);

        string s = "", d = "";
        traverseTree(lca, start, s);
        traverseTree(lca, dest, d);
        
        for(auto &c : s) c = 'U';
        return s + d;
    }
};