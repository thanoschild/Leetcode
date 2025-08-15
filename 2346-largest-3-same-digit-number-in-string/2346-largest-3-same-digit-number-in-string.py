class Solution(object):
    def largestGoodInteger(self, num):
        ans = 0
        n = len(num)
        if n < 3:
            return ""

        for i in range(2, n):
            if num[i] == num[i-1] and num[i] == num[i-2]:
                ans = max(ans, num[i])
        
        return "" if ans == 0 else ans + ans + ans