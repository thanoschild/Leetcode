/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @return {ListNode}
 */
function solve(head) {
    if(head == null) return 0;
    let carry = solve(head.next);

    let currVal = head.val * 2 + carry;
    head.val = currVal % 10;
    return Math.floor(currVal / 10);
}

var doubleIt = function(head) {
    let carry = solve(head);
    if(carry != 0) {
        let newHead = new ListNode(carry);
        newHead.next = head;
        return newHead;
    }

    return head;
};