# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def mergeInBetween(self, list1, a, b, list2):
        tail = list2
        while tail.next:
            tail = tail.next
        
        prev, curr = None, list1
        for i in range(a): 
            prev = curr
            curr = curr.next
        
        prev.next = list2
        for i in range(a, b + 1):
            curr = curr.next
        
        tail.next = curr
        return list1
        