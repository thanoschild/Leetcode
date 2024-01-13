# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):

    def dfs(self, root1, root2, level):
        if root1 == None or root2 == None: return

        if level%2 == 1:
            temp = root1.val
            root1.val = root2.val
            root2.val = temp
        
        self.dfs(root1.left, root2.right, level + 1)
        self.dfs(root1.right, root2.left, level + 1)
        
    def reverseOddLevels(self, root):
        if root == None: return root;
        self.dfs(root.left, root.right, 1)
        return root
        