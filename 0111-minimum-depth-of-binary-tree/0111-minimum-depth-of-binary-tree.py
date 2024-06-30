# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def minDepth(self, root):
        if root == None:
            return 0
        
        l = self.minDepth(root.left)
        r = self.minDepth(root.right)

        if l == 0:
            return r + 1
        if r == 0:
            return l + 1
        
        return min(r, l) + 1
        