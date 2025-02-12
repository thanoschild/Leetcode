class Solution(object):
    def maximumSum(self, nums):
        mp, ans = {}, -1

        for n in nums:
            sum, curr = 0, n
            while curr > 0:
                sum += (curr % 10)
                curr = (curr // 10)
            
            if sum in mp:
                ans = max(ans, mp[sum] + n)
                if mp[sum] < n:
                    mp[sum] = n
            else:
                mp[sum] = n
        
        return ans
        