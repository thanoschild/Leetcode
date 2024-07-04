# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def mergeNodes(self, head):
        dummy = ListNode(-1)
        sum = 0
        curr = dummy

        while head.next:
            head = head.next
            if head.val == 0:
                curr.next = ListNode(sum)
                sum = 0
                curr = curr.next
            else:
                sum += head.val
        
        return dummy.next
        