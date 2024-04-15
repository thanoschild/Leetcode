# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def solve(self, root, curr, sum):
        if root == None:
            return
        curr = curr * 10 + root.val
        if root.left == None and root.right == None:
            sum[0] += curr
        
        self.solve(root.left, curr, sum)
        self.solve(root.right, curr, sum)

    def sumNumbers(self, root):
        if root == None:
            return 0
        sum = [0] * 1
        self.solve(root, 0, sum)
        return sum[0]
        