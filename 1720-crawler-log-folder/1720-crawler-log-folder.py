class Solution(object):
    def minOperations(self, logs):
        ans = 0
        for s in logs:
            if s == "../":
                ans -= 1
                ans = max(0, ans)
            elif s == './':
                continue
            else:
                ans += 1
        
        return ans
        