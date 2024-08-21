class Solution(object):
    def solve(self, s, i, j, dp):
        if(i, j) not in dp:
            if i> j: return 0

            ans = self.solve(s, i, j - 1, dp) + 1
            for k in range(i, j):
                if s[k] == s[j]:
                    ans = min(ans, self.solve(s, i, k - 1, dp) + self.solve(s, k , j - 1, dp))
            dp[(i, j)] = ans;
        return dp[(i, j)]

    def strangePrinter(self, s):
        s = re.sub(r'(.)\1*', r'\1', s)
        dp = {}
        return self.solve(s, 0, len(s) - 1, dp)