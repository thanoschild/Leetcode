class Solution(object):
    def scoreOfString(self, s):
        n, ans = len(s), 0
        for i in range(0, n-1):
            a = ord(s[i]) - ord('a')
            b = ord(s[i+1]) - ord('a')
            ans += abs(a - b)
        
        return ans

        