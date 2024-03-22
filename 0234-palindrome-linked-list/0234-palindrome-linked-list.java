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
    public boolean isPalindrome(ListNode head) {
        ListNode fast = head, slow = head, prev = null;
        while(fast != null && fast.next != null) {
            fast = fast.next.next;
            ListNode temp = slow.next;
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
    }
}