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

function solve(root, curr, sum) {
    if(root == null) return;
    curr = curr * 10 + root.val;
    if(root.left == null && root.right == null) {
        sum[0] += curr;
    }

    solve(root.left, curr, sum);
    solve(root.right, curr, sum);
};

var sumNumbers = function(root) {
    if(root == null) return 0;
    let sum = Array(1).fill(0);
    solve(root, 0, sum);
    return sum;
};