/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @return {void} Do not return anything, modify head in-place instead.
 */
var reorderList = function(head) {
    if (head === null || head.next === null || head.next.next === null) return;
    let fast = head, slow = head, prev = null;
    while (fast !== null && fast.next !== null) {
        prev = slow;
        slow = slow.next;
        fast = fast.next.next;
    }

    prev.next = null; fast = slow;
    prev = null;
    while (fast !== null) {
        let temp = fast.next;
        fast.next = prev;
        prev = fast;
        fast = temp;
    }

    slow = head; fast = prev; prev = null;
    while (slow !== null && fast !== null) {
        prev = slow;
        let temp1 = slow.next;
        let temp2 = fast.next;
        slow.next = fast;
        slow = temp1;
        fast.next = temp1;
        fast = temp2;
    }

    if (fast !== null) prev.next.next = fast;
};