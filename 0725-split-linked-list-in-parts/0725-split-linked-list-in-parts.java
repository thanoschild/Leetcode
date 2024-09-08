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
    public ListNode[] splitListToParts(ListNode head, int k) {
        ListNode[] ans = new ListNode[k];
        int len = 0;
        ListNode curr = head, prev = null;
        while(curr != null) {
            len++;
            curr = curr.next;
        } 

        int n = len/k, rem = len % k;
        curr = head;
        for(int i = 0; i<k; i++) {
           if(curr != null) {
                int sz = (rem > 0) ? 1 : 0;
                sz += n;
                ans[i] = curr;
                for(int j = 0; j<sz; j++) {
                    prev = curr;
                    curr = curr.next;
                }
                prev.next = null;
                rem--;
           }
           else {
               ans[i] = null;
           }
        }

        return ans;
    }
}