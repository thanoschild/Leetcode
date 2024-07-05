# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def nodesBetweenCriticalPoints(self, head):
        slow = head
        curr = slow.next
        fast = curr.next if curr else None
        ans = [-1, -1]
        if fast is None:
            return ans

        critical_points = []
        idx = 0
        while fast is not None:
            idx += 1
            if (slow.val < curr.val > fast.val) or (slow.val > curr.val < fast.val):
                critical_points.append(idx)

            slow = slow.next
            curr = curr.next
            fast = fast.next

        if len(critical_points) <= 1:
            return ans

        minima = float('inf')
        maxima = critical_points[-1] - critical_points[0]
        for i in range(1, len(critical_points)):
            minima = min(minima, critical_points[i] - critical_points[i - 1])

        ans[0] = minima
        ans[1] = maxima
        return ans
        