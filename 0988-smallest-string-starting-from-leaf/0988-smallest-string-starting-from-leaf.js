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
 * @return {string}
 */

function solve(root, curr, ans) {
    if (!root) return;
    curr = String.fromCharCode('a'.charCodeAt(0) + root.val) + curr;
    if (!root.left && !root.right) {
        if (ans[0] === "") ans[0] = curr;
        else if (ans[0] > curr) ans[0] = curr;
    }

    solve(root.left, curr, ans);
    solve(root.right, curr, ans);
};

var smallestFromLeaf = function(root) {
    if (!root) return "";
    const ans = [""];
    solve(root, "", ans);
    return ans[0];
};