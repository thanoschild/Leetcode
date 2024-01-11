# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def solve(self, root, mx, mn):
        if root == None:
            return mx - mn
        mx = max(mx, root.val)
        mn = min(mn, root.val)

        return max(self.solve(root.left, mx, mn), self.solve(root.right, mx, mn))
        
    def maxAncestorDiff(self, root):
        return self.solve(root, root.val, root.val)
        