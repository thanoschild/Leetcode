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
var mergeNodes = function(head) {
    let dummy = new ListNode(-1);
    let sum = 0;
    let curr = dummy;

    while(head.next != null) {
        head = head.next;
        if(head.val == 0) {
            curr.next = new ListNode(sum);
            sum = 0;
            curr = curr.next;
        }
        else {
            sum += head.val;
        }
    }

    return dummy.next;
};