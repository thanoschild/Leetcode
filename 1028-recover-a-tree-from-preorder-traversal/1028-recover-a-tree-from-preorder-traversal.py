# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def recoverFromPreorder(self, s):
        st, i = [], 0
        while i < len(s):
            level, val = 0, ""
            while i < len(s) and s[i] == '-': 
                level += 1
                i += 1
            while i < len(s) and s[i] != '-':
                val = val + s[i]
                i += 1
            while len(st) > level:
                st.pop()

            node = TreeNode(val)
            if st:
                if st[-1].left == None:
                    st[-1].left = node
                else:
                    st[-1].right = node
            st.append(node)
            
        return st[0]
        