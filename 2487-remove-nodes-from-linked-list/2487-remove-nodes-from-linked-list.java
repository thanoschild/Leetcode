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
    public ListNode removeNodes(ListNode head) {
        Stack<ListNode> st = new Stack<>();
        while(head != null) {
            while(!st.isEmpty() && st.peek().val < head.val) {
                st.pop();
            }
            st.add(head);
            head = head.next;
        }

        ListNode prev = null;
        while(!st.isEmpty()) {
            ListNode curr = st.pop();
            curr.next = prev;
            prev = curr;
        }

        return prev;
    }
}