# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):

    def dfs(self, root, start, ans):
        if root == None:
            return 0
        x = self.dfs(root.left, start, ans)
        y = self.dfs(root.right, start, ans)

        if root.val == start:
            ans[0] = max(ans[0], max(x, y))
            return -1
        
        if x >= 0 and y >= 0:
            return max(x, y) + 1
        ans[0] = max(ans[0], abs(x) + abs(y))
        return min(x, y) - 1

    def amountOfTime(self, root, start):
        ans = [0]
        self.dfs(root, start, ans)
        return ans[0]
        
        