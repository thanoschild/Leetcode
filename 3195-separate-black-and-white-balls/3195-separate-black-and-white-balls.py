class Solution(object):
    def minimumSteps(self, s):
        ans, count = 0, 0
        for c in s:
            if c == '1':
                count += 1
            else:
                ans += count
        
        return ans