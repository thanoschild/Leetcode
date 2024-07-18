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
 * @param {number} distance
 * @return {number}
 */
function dfs(root, distance, ans) {
    if (!root) return [];
    if (!root.left && !root.right) return [1];

    let left = dfs(root.left, distance, ans);
    let right = dfs(root.right, distance, ans);

    for (let x of left) {
        for (let y of right) {
            if (x + y <= distance) ans[0]++;
        }
    }

    let v = [];
    for (let x of left) v.push(x + 1);
    for (let y of right) v.push(y + 1);

    return v;
}

var countPairs = function(root, distance) {
    const ans = new Array(1).fill(0);
    dfs(root, distance, ans);
    return ans[0];
};