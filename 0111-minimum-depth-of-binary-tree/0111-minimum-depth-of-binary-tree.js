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
 * @return {number}
 */
var minDepth = function(root) {
    if (root === null) {
        return 0;
    }

    const l = minDepth(root.left);
    const r = minDepth(root.right);

    if (l === 0) {
        return r + 1;
    }
    if (r === 0) {
        return l + 1;
    }

    return Math.min(r, l) + 1;
};