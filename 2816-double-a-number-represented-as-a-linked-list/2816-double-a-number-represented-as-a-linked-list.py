# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def solve(self, head):
        if head == None:
            return 0
        carry = self.solve(head.next)
        curr_val = head.val * 2 + carry
        head.val = curr_val % 10
        return curr_val // 10

    def doubleIt(self, head):
        carry = self.solve(head)
        if carry != 0:
            new_head = ListNode(carry)
            new_head.next = head
            return new_head
        
        return head
        