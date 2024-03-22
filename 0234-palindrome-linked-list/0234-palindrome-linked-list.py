# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def isPalindrome(self, head):
        fast, slow ,prev = head, head, None
        while fast and fast.next:
            fast = fast.next.next
            temp = slow.next
            slow.next = prev
            prev = slow
            slow = temp

        if fast: fast = slow.next
        else: fast = slow
        slow = prev

        while fast and slow:
            if fast.val != slow.val: 
                return False
            fast = fast.next
            slow = slow.next
        
        return True
        