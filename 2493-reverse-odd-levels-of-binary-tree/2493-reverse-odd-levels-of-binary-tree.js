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
function solve(root1, root2, level) {
    if(root1 == null || root2 == null) return;

    if(level % 2 === 1) {
        const temp = root1.val;
        root1.val = root2.val;
        root2.val = temp;
    }
    solve(root1.left, root2.right, level + 1);
    solve(root1.right, root2.left, level + 1);
}

var reverseOddLevels = function(root) {
    if(root == null) return root;
    solve(root.left, root.right, 1);
    return root;
};