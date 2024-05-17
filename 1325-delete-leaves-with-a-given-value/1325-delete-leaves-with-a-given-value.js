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
 * @param {number} target
 * @return {TreeNode}
 */
function solve(root, target) {
    if(root == null) return -1;
    let l = solve(root.left, target);
    if(l == -1) root.left = null;
    let r = solve(root.right, target);
    if(r == -1) root.right = null;

    if(l == -1 && r == -1 && root.val == target) {
        return -1;
    }

    return 0;
};
var removeLeafNodes = function(root, target) {
    let ans = solve(root, target);
    return ans == -1 ? null : root;
};