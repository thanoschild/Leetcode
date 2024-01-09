# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def solve(self, root, ans):
        if root == None:
            return
        self.solve(root.left, ans)
        if root.left == None and root.right == None:
            ans.append(root.val)
        self.solve(root.right, ans)
        
    def leafSimilar(self, root1, root2):
        ans1, ans2 = [], []
        self.solve(root1, ans1)
        self.solve(root2, ans2)

        if len(ans1) != len(ans2):
            return False
        for i in range(len(ans1)):
            if ans1[i] != ans2[i]:
                return False
            
        return True
        