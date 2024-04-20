# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def postOrder(self, root, ans):
        if root == None:
            return
        self.postOrder(root.left, ans)
        self.postOrder(root.right, ans)
        ans.append(root.val)

    def postorderTraversal(self, root):
        ans = []
        self.postOrder(root, ans)
        return ans
        