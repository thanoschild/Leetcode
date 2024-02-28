# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def findBottomLeftValue(self, root):
        if root is None:
            return -1
        ans = -1
        pq = []
        pq.append(root)

        while pq:
            n = len(pq)
            for i in range(n):
                t = pq.pop(0)
                if i == 0:
                    ans = t.val
                
                if t.left:
                    pq.append(t.left)
                if t.right:
                    pq.append(t.right)
        
        return ans
        