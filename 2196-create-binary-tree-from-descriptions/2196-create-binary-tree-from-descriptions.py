# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def createBinaryTree(self, arr):
        mp, st = {}, []
        for it in arr:
            if mp.get(it[0], -1) == -1: mp[it[0]] = TreeNode(it[0])
            if mp.get(it[1], -1) == -1: mp[it[1]] = TreeNode(it[1])

            if it[2] == 1: mp.get(it[0]).left = mp.get(it[1])
            else: mp.get(it[0]).right = mp.get(it[1])
            st.append(it[1])

        for it in arr:
            if it[0] not in st:
                return mp.get(it[0])

        return None
        
