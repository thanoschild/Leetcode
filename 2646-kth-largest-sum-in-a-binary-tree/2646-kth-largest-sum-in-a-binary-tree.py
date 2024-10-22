# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

from collections import deque
import heapq

class Solution(object):
    def kthLargestLevelSum(self, root, k):
        pq = []
        q = deque([root])

        while q:
            n = len(q)
            level_sum = 0
            for i in range(n):
                node = q.popleft()
                level_sum += node.val

                if node.left:
                    q.append(node.left)
                if node.right:
                    q.append(node.right)
                
            heapq.heappush(pq, level_sum)
            if len(pq) > k:
                heapq.heappop(pq)
            
        if len(pq) < k:
            return -1
        
        return heapq.heappop(pq)

        