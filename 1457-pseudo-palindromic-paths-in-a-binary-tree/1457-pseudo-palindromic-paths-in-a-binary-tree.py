# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):

    def solve(self, root, mp, ans):
        if root == None:
            return
        mp[root.val] = mp.get(root.val, 0) + 1
        if(root.left == None and root.right == None):
            odd = 0
            for value in mp.values():
                if value % 2 == 1:
                     odd += 1
            if odd <= 1:
                ans[0] += 1
        self.solve(root.left, mp, ans)
        self.solve(root.right, mp, ans)
        mp[root.val] = mp.get(root.val, 0) - 1

    def pseudoPalindromicPaths (self, root):
        mp, ans = {}, [0]
        self.solve(root, mp, ans)
        return ans[0]
        