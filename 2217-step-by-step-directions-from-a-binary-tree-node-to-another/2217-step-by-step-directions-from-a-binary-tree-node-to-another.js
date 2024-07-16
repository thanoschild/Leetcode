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
 * @param {number} startValue
 * @param {number} destValue
 * @return {string}
 */
function getLca(root, start, dest) {
    if (!root) return null;
    if (root.val === start || root.val === dest) return root;

    let left = getLca(root.left, start, dest);
    let right = getLca(root.right, start, dest);

    if (left && right) return root;

    return left ? left : right;
}

function traverseTree(root, target, path) {
    if (!root) return false;
    if (root.val === target) return true;

    path.push('L');
    if (traverseTree(root.left, target, path)) return true;
    path.pop();

    path.push('R');
    if (traverseTree(root.right, target, path)) return true;
    path.pop();

    return false;
}

var getDirections = function(root, start, dest) {
    let lca = getLca(root, start, dest);

    let startPath = [];
    let destPath = [];
    traverseTree(lca, start, startPath);
    traverseTree(lca, dest, destPath);

    startPath = startPath.map(() => 'U');
    return startPath.join('') + destPath.join('');
};