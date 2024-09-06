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
    public ListNode modifiedList(int[] nums, ListNode head) {
        HashSet<Integer> st = new HashSet<>();
        for(int n : nums) st.add(n);

        ListNode dummy = new ListNode(-1);
        ListNode temp = dummy;

        while(head != null) {
            if(!st.contains(head.val)) {
                temp.next = head;
                temp = temp.next;
            }
            head = head.next;
        }

        temp.next = null;
        return dummy.next;
    }
}