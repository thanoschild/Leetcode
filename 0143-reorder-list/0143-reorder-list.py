# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def reorderList(self, head):
        if not head or not head.next or not head.next.next: return
        fast, slow, prev = head, head, None
        while fast and fast.next:
            prev = slow
            slow = slow.next
            fast = fast.next.next
        
        prev.next = None
        fast, prev = slow, None
        while fast:
            temp = fast.next
            fast.next = prev
            prev = fast
            fast = temp
        
        slow, fast = head, prev
        prev = None
        while slow and fast:
            prev = slow
            temp1 = slow.next
            temp2 = fast.next
            slow.next = fast
            slow = temp1
            fast.next = temp1
            fast = temp2

        if fast: prev.next.next = fast
        