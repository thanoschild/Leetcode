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
 * @return {TreeNode}
 */
function inorder(root, node_arr) {
    if(root == null) return null;
    inorder(root.left, node_arr);
    node_arr.push(root);
    inorder(root.right, node_arr)
}

function balanceTree(start, end, node_arr) {
    if(start > end) return null;
    let mid = Math.floor((start + end)/2);
    let root = node_arr[mid];
    root.left = balanceTree(start, mid - 1, node_arr);
    root.right = balanceTree(mid+1, end, node_arr);
    return root;
}

var balanceBST = function(root) {
    node_arr = [];
    inorder(root, node_arr);
    return balanceTree(0, node_arr.length - 1, node_arr)
};