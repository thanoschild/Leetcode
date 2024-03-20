/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} list1
 * @param {number} a
 * @param {number} b
 * @param {ListNode} list2
 * @return {ListNode}
 */
var mergeInBetween = function(list1, a, b, list2) {
    let tail = list2
    while(tail.next != null) {
        tail = tail.next;
    }

    let prev = null, curr = list1
    for(let i = 0; i<a; i++) {
        prev = curr;
        curr = curr.next;
    }

    prev.next = list2;
    for(let i = a; i<=b; i++) {
        curr = curr.next;
    }

    tail.next = curr;
    return list1;
};