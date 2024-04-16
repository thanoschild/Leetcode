# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def addOneRow(self, root, val, depth):
        if depth == 1:
            new_node = TreeNode(val)
            new_node.left = root
            return new_node

        queue = deque([root])
        level = 0
        flag = False

        while queue:
            level += 1
            n = len(queue)
            if flag:
                break

            for _ in range(n):
                curr = queue.popleft()

                if level == depth - 1:
                    flag = True

                    new_node1 = TreeNode(val)
                    new_node1.left = curr.left
                    curr.left = new_node1

                    new_node2 = TreeNode(val)
                    new_node2.right = curr.right
                    curr.right = new_node2
                else:
                    if curr.left:
                        queue.append(curr.left)
                    if curr.right:
                        queue.append(curr.right)

        return root
                
        