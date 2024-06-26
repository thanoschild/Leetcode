# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def inorder(self, root, node_list):
        if not root:
            return None
        self.inorder(root.left, node_list)
        node_list.append(root)
        self.inorder(root.right, node_list)
    
    def balance_tree(self, start, end, node_list):
        if start > end:
            return None
        mid = (start + end)/2
        root = node_list[mid]
        root.left = self.balance_tree(start, mid - 1, node_list)
        root.right = self.balance_tree(mid + 1, end, node_list)
        return root

    def balanceBST(self, root):
        node_list = []
        self.inorder(root, node_list)
        return self.balance_tree(0, len(node_list) - 1, node_list)
        