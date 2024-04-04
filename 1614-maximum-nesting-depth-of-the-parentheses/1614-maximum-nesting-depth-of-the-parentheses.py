class Solution(object):
    def maxDepth(self, s):
        count, ans = 0, 0
        for c in s:
            if c == '(':
                count += 1
            elif c == ')':
                count -= 1
            ans = max(ans, count)
        
        return ans
        