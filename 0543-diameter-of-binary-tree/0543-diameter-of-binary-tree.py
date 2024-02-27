# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def solve(self, root, ans):
        if root == None:
            return 0
        left = self.solve(root.left, ans)
        right = self.solve(root.right, ans)
        ans[0] = max(ans[0], left + right)
        return 1 + max(left, right)
        
    def diameterOfBinaryTree(self, root):
        if root == None:
            return 0
        ans = [0]
        self.solve(root, ans)
        return ans[0]
        