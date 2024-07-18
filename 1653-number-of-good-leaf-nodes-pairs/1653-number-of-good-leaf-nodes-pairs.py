# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def __init__(self):
        self.ans = 0

    def dfs(self, root, distance):
        if not root:
            return []
        if not root.left and not root.right:
            return [1]

        left = self.dfs(root.left, distance)
        right = self.dfs(root.right, distance)

        for x in left:
            for y in right:
                if x + y <= distance:
                    self.ans += 1

        v = []
        for x in left:
            v.append(x + 1)
        for y in right:
            v.append(y + 1)

        return v

    def countPairs(self, root, distance):
        self.dfs(root, distance)
        return self.ans
        