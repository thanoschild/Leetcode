class Solution(object):
    def minSteps(self, n):
        if n == 1:
            return 0
        dp = {}

        def solve(count, paste):
            if count == n:
                return 0
            if count > n:
                return 1000
            if (count, paste) in dp:
                return dp[(count, paste)]
            
            ans1 = 1 + solve(count + paste, paste)
            ans2 = 2 + solve(count + count, count)
            dp[(count, paste)] = min(ans1, ans2)

            return dp[(count, paste)]
        
        return 1 + solve(1, 1)
        
        