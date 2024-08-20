class Solution(object):
    def stoneGameII(self, piles):
        n = len(piles)
        dp = [[-1 for _ in range(2*n+1)] for _ in range(n+1)]
        
        def solve(i, m):
            if i>=n:
                return 0
            if dp[i][m] != -1:
                return dp[i][m]
            
            ans, total = float('-inf'), 0
            for j in range(0, 2*m):
                if i + j < n:
                    total += piles[i+j]
                    ans = max(ans, total - solve(i+j+1, max(m, j+1)))
                else:
                    break
            dp[i][m] = ans
            return ans
        
        _sum = sum(piles)
        return (_sum + solve(0, 1))//2