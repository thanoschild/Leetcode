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
    public ListNode removeZeroSumSublists(ListNode head) {
        ListNode dummy = new ListNode(0);
        dummy.next = head;
        int prefix = 0;
        ListNode curr = dummy;
        HashMap<Integer, ListNode> mp = new HashMap<>();

        while(curr != null) {
            prefix += curr.val;
            mp.put(prefix, curr);
            curr = curr.next;
        }

        prefix = 0;
        curr = dummy;
        while(curr != null) {
            prefix += curr.val;
            curr.next = mp.get(prefix).next;
            curr = curr.next;
        }

        return dummy.next;
    }
}