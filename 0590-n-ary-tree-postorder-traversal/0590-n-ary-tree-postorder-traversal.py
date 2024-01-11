"""
# Definition for a Node.
class Node(object):
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children
"""

class Solution(object):
    def postorder(self, root):
        ans = []
        if root == None: return ans

        st = []
        st.append(root)

        while st:
            t = st.pop()
            for child in t.children:
                st.append(child)
            ans.append(t.val)
        
        ans.reverse()
        return ans