/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {number[][]} descriptions
 * @return {TreeNode}
 */
var createBinaryTree = function(desc) {
    const mp = new Map();
    const st = new Set();

    for(let it of desc) {
        if(!mp.has(it[0])) mp.set(it[0], new TreeNode(it[0]));
        if(!mp.has(it[1])) mp.set(it[1], new TreeNode(it[1]));
        
        if(it[2] == 1) mp.get(it[0]).left = mp.get(it[1]);
        else mp.get(it[0]).right = mp.get(it[1]);

        st.add(it[1]);
    }

    for(let it of desc) {
        if(!st.has(it[0])) return mp.get(it[0]);
    }

    return null;
};