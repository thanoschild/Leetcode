# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def dfs(self, root):
        if root == None: return [None, 0]

        left = self.dfs(root.left)
        right = self.dfs(root.right)

        if left[1] > right[1]: return [left[0], left[1] + 1]
        if right[1] > left[1]: return [right[0], right[1] + 1]

        return [root, left[1] + 1]
 
    def lcaDeepestLeaves(self, root):
        return self.dfs(root)[0]
        