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
 * @param {number} k
 * @return {number}
 */
var kthLargestLevelSum = function(root, k) {
    let pq = []; 
    let q = [root]; 

    while (q.length > 0) {
        let n = q.length;
        let sum = 0;

        for (let i = 0; i < n; i++) {
            let node = q.shift();
            sum += node.val;

            if (node.left) q.push(node.left);
            if (node.right) q.push(node.right);
        }

        pq.push(sum);
    }

    if(pq.length < k) return -1;

    pq.sort((a, b) => b - a);
    return pq[k-1];
};