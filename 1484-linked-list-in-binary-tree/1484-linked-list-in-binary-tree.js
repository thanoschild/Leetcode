/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {ListNode} head
 * @param {TreeNode} root
 * @return {boolean}
 */
function check(head, root) {
    if(head == null) return true;
    if(root == null) return false;
    return head.val == root.val && (check(head.next, root.left) || check(head.next, root.right));
}
    
var isSubPath = function(head, root) {
    if(root == null) return false;
    return check(head, root) || isSubPath(head, root.left) || isSubPath(head, root.right);
};