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
function postOrder(root, moves) {
    if(root == null) return 0;
    let l = postOrder(root.left, moves);
    let r = postOrder(root.right, moves);
    moves[0] += Math.abs(l) + Math.abs(r);
    return root.val + l + r - 1;
};

var distributeCoins = function(root) {
    let moves = [0];
    postOrder(root, moves);
    return moves[0];
};