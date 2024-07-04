/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode mergeNodes(ListNode head) {
        ListNode dummy = new ListNode(-1);
        int sum = 0;
        ListNode curr = dummy;

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
    }
}