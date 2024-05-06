# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def removeNodes(self, head):
        st = []
        while head:
            while st and st[-1].val < head.val:
                st.pop()
            st.append(head)
            head = head.next
        
        prev = None
        while st:
            curr = st.pop()
            curr.next = prev
            prev = curr
        
        return prev
        