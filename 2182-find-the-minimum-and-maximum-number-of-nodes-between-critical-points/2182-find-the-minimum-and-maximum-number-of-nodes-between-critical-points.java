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
    public int[] nodesBetweenCriticalPoints(ListNode head) {
        ListNode slow = head;
        ListNode curr = slow.next;
        ListNode fast = curr != null ? curr.next : null;
        int[] ans = new int[]{-1, -1};
        if (fast == null) return ans;

        List<Integer> v = new ArrayList<>();
        int idx = 0;
        while (fast != null) {
            idx++;
            if (slow.val < curr.val && curr.val > fast.val) {
                v.add(idx);
            } else if (slow.val > curr.val && curr.val < fast.val) {
                v.add(idx);
            }

            slow = slow.next;
            curr = curr.next;
            fast = fast.next;
        }

        if (v.size() <= 1) return ans;
        int minima = Integer.MAX_VALUE;
        int maxima = Integer.MIN_VALUE;
        for (int i = 1; i < v.size(); i++) {
            minima = Math.min(minima, v.get(i) - v.get(i - 1));
        }
        maxima = v.get(v.size() - 1) - v.get(0);
        ans[0] = minima;
        ans[1] = maxima;
        return ans;
    }
}