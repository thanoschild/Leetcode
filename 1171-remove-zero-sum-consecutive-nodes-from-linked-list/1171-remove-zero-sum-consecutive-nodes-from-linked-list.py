# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def removeZeroSumSublists(self, head):
        dummy = ListNode(0)
        dummy.next = head
        mp = {}
        prefix, curr = 0, dummy

        while curr:
            prefix += curr.val
            mp[prefix] = curr
            curr = curr.next
        
        prefix, curr = 0, dummy
        while curr:
            prefix += curr.val
            curr.next = mp[prefix].next
            curr = curr.next
        
        return dummy.next
        