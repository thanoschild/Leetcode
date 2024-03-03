# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def removeNthFromEnd(self, head, n):
        fast, slow = head, head
        while n > 0:
            fast = fast.next
            n -= 1
        
        if fast is None:
            return head.next
        
        while fast.next:
            fast = fast.next
            slow = slow.next
        
        to_delete = slow.next
        slow.next = slow.next.next
        del to_delete

        return head
        