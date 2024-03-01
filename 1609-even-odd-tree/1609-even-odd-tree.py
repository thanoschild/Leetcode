# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def isEvenOddTree(self, root):
        if root == None:
            return True
        pq, even = [], True
        pq.append(root)

        while pq:
            preval = float('-inf') if even else float('inf')
            n = len(pq)
            for i in range(n):
                t = pq.pop(0)
                if even and (t.val % 2 == 0 or t.val <= preval):
                    return False
                if not even and (t.val % 2 == 1 or t.val >= preval):
                    return False
                preval = t.val
                if t.left != None:
                    pq.append(t.left)
                if t.right != None:
                    pq.append(t.right)
            even = not even
        
        return True
                
        