class Solution(object):
    def divideArray(self, nums, k):
        n = len(nums)
        if n % 3 != 0: return []

        ans = []
        nums.sort()

        for i in range(0, n, 3):
            if nums[i+2] - nums[i] > k: return []
            curr = [nums[i], nums[i+1], nums[i+2]]
            ans.append(curr)
        
        return ans
        