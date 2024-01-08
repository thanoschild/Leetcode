# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):

    def solve(self, root, low, high, _sum):
        if root == None:
            return
        self.solve(root.left, low, high, _sum)
        if root.val >= low and root.val <= high:
            _sum[0] += root.val
        self.solve(root.right, low, high, _sum)
    
    def rangeSumBST(self, root, low, high):
        _sum = [0]
        self.solve(root, low, high, _sum)
        return _sum[0]
        