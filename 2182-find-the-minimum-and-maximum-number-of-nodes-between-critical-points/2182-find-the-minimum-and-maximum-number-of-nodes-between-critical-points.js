/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @return {number[]}
 */
var nodesBetweenCriticalPoints = function(head) {
    let slow = head;
    let curr = slow.next;
    let fast = curr ? curr.next : null;
    const ans = [-1, -1];
    if (!fast) return ans;

    const criticalPoints = [];
    let idx = 0;
    while (fast) {
        idx++;
        if ((slow.val < curr.val && curr.val > fast.val) || (slow.val > curr.val && curr.val < fast.val)) {
            criticalPoints.push(idx);
        }

        slow = slow.next;
        curr = curr.next;
        fast = fast.next;
    }

    if (criticalPoints.length <= 1) return ans;

    let minima = Number.MAX_VALUE;
    const maxima = criticalPoints[criticalPoints.length - 1] - criticalPoints[0];
    for (let i = 1; i < criticalPoints.length; i++) {
        minima = Math.min(minima, criticalPoints[i] - criticalPoints[i - 1]);
    }

    ans[0] = minima;
    ans[1] = maxima;
    return ans;
};