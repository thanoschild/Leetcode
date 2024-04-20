/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number[]}
 */
var postorderTraversal = function(root) {
    const ans = [];

    postOrder = (root) => {
        if(root == null) return;
        postOrder(root.left);
        postOrder(root.right);
        ans.push(root.val);
    }

    postOrder(root);
    return ans;
};