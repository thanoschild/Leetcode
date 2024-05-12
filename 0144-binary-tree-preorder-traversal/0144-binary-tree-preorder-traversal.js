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
var preorderTraversal = function(root) {
    let ans = []
    if(root === null) return ans;
    let curr;

    while(root !== null) {
        if(root.left !== null) {
            curr = root.left;
            while(curr.right !== null && curr.right !== root) {
                curr = curr.right;
            }

            if(curr.right != null) {
                curr.right = null;
                root = root.right;
            }
            else {
                ans.push(root.val);
                curr.right = root;
                root = root.left;
            }
        }
        else {
            ans.push(root.val);
            root = root.right;
        }
    }

    return ans;
};