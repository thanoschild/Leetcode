# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def evaluateTree(self, root):
        if root.val == 0:
            return False
        if root.val == 1:
            return True
        
        l, r = self.evaluateTree(root.left), self.evaluateTree(root.right)
        return (l | r) if root.val == 2 else (l & r);
        