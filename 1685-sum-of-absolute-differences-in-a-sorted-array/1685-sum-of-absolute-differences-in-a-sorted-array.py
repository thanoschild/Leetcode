class Solution(object):
    def getSumAbsoluteDifferences(self, nums):
        total = sum(nums)
        left, right = 0, total
        ans = []
        
        for i, n in enumerate(nums):
            right -= n
            ans.append(n * i - left + right - n * (len(nums) - i - 1))
            left += n
            
        return ans
        