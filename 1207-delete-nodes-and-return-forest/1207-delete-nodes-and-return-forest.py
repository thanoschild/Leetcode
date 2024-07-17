# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def dfs(self, root, st, ans):
        if not root:
            return None
        root.left, root.right = self.dfs(root.left, st, ans), self.dfs(root.right, st, ans)
        
        if root.val in st:
            if root.left: ans.append(root.left)
            if root.right: ans.append(root.right)
            return None
        
        return root

    def delNodes(self, root, to_delete):
        ans = []
        st = set(to_delete)
        root = self.dfs(root, st, ans)
        if root: ans.append(root)

        return ans
        