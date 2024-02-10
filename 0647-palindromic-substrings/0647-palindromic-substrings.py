class Solution(object):
    def solve(self, i, j, s):
        count = 0
        while i >= 0 and j < len(s) and s[i] == s[j]:
            i -= 1
            j += 1
            count += 1
        
        return count


    def countSubstrings(self, s):
        n, ans = len(s), 0
        for i in range(n):
            odd = self.solve(i, i, s)
            even = self.solve(i, i+1, s)
            ans += (odd + even)
        
        return ans
        