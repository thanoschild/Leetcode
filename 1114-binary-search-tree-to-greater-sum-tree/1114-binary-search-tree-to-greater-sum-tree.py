# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def __init__(self):
        self._sum = 0

    def bstToGst(self, root):
        if not root:
            return None
        self.bstToGst(root.right)
        self._sum = root.val + self._sum
        root.val = self._sum
        self.bstToGst(root.left)
        return root
        