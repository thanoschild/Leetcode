# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def splitListToParts(self, head, k):
        length = 0
        curr = head
        while curr:
            length += 1
            curr = curr.next

        part_size = length // k
        extra_parts = length % k

        result = []
        curr = head
        for i in range(k):
            size = part_size + (1 if extra_parts > 0 else 0)
            if size > 0:
                result.append(curr)
            else:
                result.append(None)
            
            for j in range(size - 1):
                if curr:
                    curr = curr.next

            if curr:
                next_part = curr.next
                curr.next = None
                curr = next_part
 
            if extra_parts > 0:
                extra_parts -= 1

        return result
        