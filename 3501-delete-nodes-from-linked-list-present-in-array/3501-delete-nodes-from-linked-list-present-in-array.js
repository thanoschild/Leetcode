/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {number[]} nums
 * @param {ListNode} head
 * @return {ListNode}
 */
var modifiedList = function(nums, head) {
    const st = new Set(nums); // Use a Set for fast lookup

    const dummy = new ListNode(-1); // Dummy node as a placeholder
    let temp = dummy;

    while (head !== null) {
        if (!st.has(head.val)) {
            temp.next = head;
            temp = temp.next;
        }
        head = head.next;
    }

    temp.next = null; // Ensure the list ends properly
    return dummy.next;
};