# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def modifiedList(self, nums, head):
        st = set(nums)  # Use a set for quick lookup

        dummy = ListNode(-1)  # Dummy node to act as a placeholder
        temp = dummy

        while head is not None:
            if head.val not in st:
                temp.next = head
                temp = temp.next
            head = head.next

        temp.next = None  # Ensure the list ends correctly
        return dummy.next
        