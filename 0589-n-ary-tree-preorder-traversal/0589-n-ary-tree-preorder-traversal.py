"""
# Definition for a Node.
class Node(object):
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children
"""

class Solution(object):
    def preorder(self, root):
        ans = []
        if root == None: return ans

        st = []
        st.append(root)
        while st:
            t = st.pop()
            ans.append(t.val)

            n = len(t.children)
            for i in range(n - 1, -1, -1):
                st.append(t.children[i])
        
        return ans