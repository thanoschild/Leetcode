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
    public void reorderList(ListNode head) {
        if(head == null || head.next == null || head.next.next == null) return;
        ListNode fast = head, slow = head, prev = null;
        while(fast != null && fast.next != null) {
            prev = slow;
            slow = slow.next;
            fast = fast.next.next;
        }

        prev.next = null; fast = slow;
        prev = null;
        while(fast != null) {
            ListNode temp = fast.next;
            fast.next = prev;
            prev = fast;
            fast = temp;
        }

        slow = head; fast = prev; prev = null;
        while(slow != null && fast != null) {
            prev = slow;
            ListNode temp1 = slow.next;
            ListNode temp2 = fast.next;
            slow.next = fast;
            slow = temp1;
            fast.next = temp1;
            fast = temp2;
        }

        if(fast != null) prev.next.next = fast;
    }
}