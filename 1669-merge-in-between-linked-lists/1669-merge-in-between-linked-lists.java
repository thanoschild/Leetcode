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
    public ListNode mergeInBetween(ListNode list1, int a, int b, ListNode list2) {
        ListNode tail = list2;
        while(tail.next != null) tail = tail.next;

        ListNode prev = null, curr = list1;
        for(int i = 0; i<a; i++) {
            prev = curr;
            curr = curr.next;
        }

        prev.next = list2;
        for(int i = a; i<=b; i++) curr = curr.next;

        tail.next = curr;
        return list1;
    }
}