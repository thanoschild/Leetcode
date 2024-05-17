# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def solve(self, root, target):
        if root is None:
            return -1
        l = self.solve(root.left, target)
        if l == -1:
            root.left = None
        r = self.solve(root.right, target)
        if r == -1:
            root.right = None
        if l == -1 and r == -1 and root.val == target:
            return -1
        return 0
        
    def removeLeafNodes(self, root, target):
        ans = self.solve(root, target)
        return None if ans == -1 else root
        