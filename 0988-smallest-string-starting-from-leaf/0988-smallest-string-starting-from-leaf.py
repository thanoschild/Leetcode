# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def solve(self, root, curr, ans):
        if not root:
            return
        curr = chr(ord('a') + root.val) + curr
        if not root.left and not root.right:
            if ans[0] == "":
                ans[0] = curr
            elif ans[0] > curr:
                ans[0] = curr

        self.solve(root.left, curr, ans)
        self.solve(root.right, curr, ans)


    def smallestFromLeaf(self, root):
        if not root:
            return ""
        ans = [""]
        self.solve(root, "", ans)
        return ans[0]
        