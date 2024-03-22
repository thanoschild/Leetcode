/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @return {boolean}
 */
var isPalindrome = function(head) {
    let fast = head, slow = head, prev = null;
    while(fast != null && fast.next != null) {
        fast = fast.next.next;
        let temp = slow.next;
        slow.next = prev;
        prev = slow;
        slow = temp;
    }

    if(fast != null) fast = slow.next;
    else fast = slow;
    slow = prev;

    while(fast != null && slow != null) {
        if(fast.val != slow.val) return false;
        fast = fast.next;
        slow = slow.next;
    }

    return true;
};