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
    private int solve(ListNode head) {
        if(head == null) return 0;
        int carry = solve(head.next);

        int currVal = head.val * 2 + carry;
        head.val = currVal % 10;
        return currVal / 10;
    }
    
    public ListNode doubleIt(ListNode head) {
        int carry = solve(head);
        if(carry != 0) {
            ListNode newHead = new ListNode(carry);
            newHead.next = head;
            return newHead;
        }

        return head;
    }
}