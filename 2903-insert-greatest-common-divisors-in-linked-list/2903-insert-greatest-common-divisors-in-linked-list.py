# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def gcd(self, a, b):
        if b == 0: 
            return a
        return self.gcd(b, a % b)

    def insertGreatestCommonDivisors(self, head):
        curr = head
        while curr.next:
            val = self.gcd(curr.val, curr.next.val)
            temp, new_node = curr.next, ListNode(val)
            curr.next = new_node
            new_node.next = temp
            curr = temp
        
        return head
        