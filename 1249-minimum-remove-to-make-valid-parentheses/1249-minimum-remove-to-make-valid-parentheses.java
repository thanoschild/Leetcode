class Solution(object):
    def minRemoveToMakeValid(self, s):
        stack = []
        chars = list(s)

        for i in range(len(chars)):
            if chars[i] == '(':
                stack.append(i)
            elif chars[i] == ')':
                if stack:
                    stack.pop()
                else:
                    chars[i] = '*'

        while stack:
            chars[stack.pop()] = '*'

        return ''.join(char for char in chars if char != '*')

        