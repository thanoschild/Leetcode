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
 * @param {number} val
 * @param {number} depth
 * @return {TreeNode}
 */
var addOneRow = function(root, val, depth) {
    if(depth == 1) {
        const newNode = new TreeNode(val);
        newNode.left = root;
        return newNode;
    }

    const queue = []
    queue.push(root);
    let level = 0, flag = false;

    while(queue.length > 0) {
        let n = queue.length;
        level++;
        if(flag) break;

        for(let i = 0; i<n; i++) {
            let curr = queue.shift();

            if(level == depth - 1) {
                flag = true;

                let newNode1 = new TreeNode(val);
                newNode1.left = curr.left;
                curr.left = newNode1;

                let newNode2 = new TreeNode(val);
                newNode2.right = curr.right;
                curr.right = newNode2;
            }
            else {
                if(curr.left != null) queue.push(curr.left);
                if(curr.right != null) queue.push(curr.right);
            }
        }
    }

    return root;
};