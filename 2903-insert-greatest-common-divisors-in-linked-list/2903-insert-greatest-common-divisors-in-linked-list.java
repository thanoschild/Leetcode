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
    private int gcd(int a, int b) {
        if(b == 0) return a;
        return gcd(b, a % b);
    }

    public ListNode insertGreatestCommonDivisors(ListNode head) {
        ListNode curr = head;
        while(curr.next != null) {
            int val = gcd(curr.val, curr.next.val);
            ListNode temp = curr.next, newNode = new ListNode(val);
            curr.next = newNode;
            newNode.next = temp;
            curr = temp;
        }

        return head;
    }
}