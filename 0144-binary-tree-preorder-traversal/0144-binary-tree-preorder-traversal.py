# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def preorderTraversal(self, root):
        ans = []
        if root is None:
            return ans
        
        while root:
            if root.left:
                curr = root.left
                while curr.right and curr.right != root:
                    curr = curr.right
                
                if curr.right:
                    curr.right = None
                    root = root.right
                else:
                    ans.append(root.val)
                    curr.right = root
                    root = root.left
            else:
                ans.append(root.val)
                root = root.right

        return ans
        