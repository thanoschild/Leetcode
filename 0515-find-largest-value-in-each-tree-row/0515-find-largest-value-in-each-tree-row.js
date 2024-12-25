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
 * @return {number[]}
 */
var largestValues = function(root) {
    ans = [];
    if(root == null) return ans;

    queue = [];
    queue.push(root);

    while(queue.length > 0) {
        const n = queue.length;
        let maxVal = -Infinity;

        for(let i = 0; i<n; i++) {
            const node = queue.shift();
            maxVal = Math.max(maxVal, node.val);

            if(node.left != null) queue.push(node.left);
            if(node.right != null) queue.push(node.right);
        }

        ans.push(maxVal);
    }

    return ans;
};