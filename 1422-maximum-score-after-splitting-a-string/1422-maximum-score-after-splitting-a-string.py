class Solution(object):
    def maxScore(self, s):
        ones, zeros, ans = 0, 0, float('-inf')
        for i in range(len(s)):
            if s[i] == '0':
                zeros += 1
            else:
                ones += 1
            if i != len(s) - 1:
                ans = max(ans, zeros - ones)
                
        return ans + ones
        