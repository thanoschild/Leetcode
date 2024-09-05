class Solution(object):
    def missingRolls(self, rolls, mean, n):
        sum_rolls = sum(rolls)
        m = len(rolls)
        missing_sum = mean * (n + m) - sum_rolls
        
        if missing_sum < n or missing_sum > n * 6:
            return []
        
        val = missing_sum // n
        rem = missing_sum % n
        ans = [val] * n
        
        for i in range(rem):
            ans[i] += 1
        
        return ans
        