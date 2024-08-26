/**
 * // Definition for a _Node.
 * function _Node(val,children) {
 *    this.val = val;
 *    this.children = children;
 * };
 */

/**
 * @param {_Node|null} root
 * @return {number[]}
 */
var postorder = function(root) {
    const ans = [];
    if(root === null) return ans;

    const stack = [];
    stack.push(root);
    while(stack.length > 0) {
        const node = stack.pop();
        for(let child of node.children) {
            stack.push(child);
        }

        ans.push(node.val);
    }

    ans.reverse();
    return ans;
};