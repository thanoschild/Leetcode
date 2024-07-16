# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def getLca(self, root, start, dest):
        if not root:
            return None
        if root.val == start or root.val == dest:
            return root

        left = self.getLca(root.left, start, dest)
        right = self.getLca(root.right, start, dest)

        if left and right:
            return root

        return left if left else right

    def traverseTree(self, root, target, path):
        if not root:
            return False
        if root.val == target:
            return True

        path.append('L')
        if self.traverseTree(root.left, target, path):
            return True
        path.pop()

        path.append('R')
        if self.traverseTree(root.right, target, path):
            return True
        path.pop()

        return False

    def getDirections(self, root, start, dest):
        lca = self.getLca(root, start, dest)

        start_path = []
        dest_path = []
        self.traverseTree(lca, start, start_path)
        self.traverseTree(lca, dest, dest_path)

        start_path = ['U'] * len(start_path)
        return ''.join(start_path) + ''.join(dest_path)
        