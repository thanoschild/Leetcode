# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def post_order(self, root, moves):
        if root == None:
            return 0
        l = self.post_order(root.left, moves)
        r = self.post_order(root.right, moves)
        moves[0] += abs(l) + abs(r)
        return root.val + r + l - 1

    def distributeCoins(self, root):
        moves = [0]*1
        self.post_order(root, moves)
        return moves[0]
        