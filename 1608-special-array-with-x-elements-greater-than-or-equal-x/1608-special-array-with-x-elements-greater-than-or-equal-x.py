class Solution(object):
    def specialArray(self, nums):
        n = len(nums)
        count = [0] * (n + 1)

        for num in nums:
            if num >= n:
                count[n] += 1
            else:
                count[num] += 1
        
        ans = 0
        for i in range(n, 0, -1):
            ans += count[i]
            if ans == i:
                return ans
        
        return -1
        