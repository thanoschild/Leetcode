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
 * @param {number[]} to_delete
 * @return {TreeNode[]}
 */
function dfs(root, st, ans) {
    if(root == null) return null;
    root.left = dfs(root.left, st, ans);
    root.right = dfs(root.right, st, ans);
    
    if(st.has(root.val)) {
        if(root.left != null) ans.push(root.left);
        if(root.right != null) ans.push(root.right);
        return null;
    }

    return root;
}

var delNodes = function(root, to_delete) {
    const ans = [];
    const st = new Set(to_delete);
    
    root = dfs(root, st, ans);
    if(root != null) ans.push(root);

    return ans;
};