class Solution(object):
    def largestPerimeter(self, nums):
        presum = []
        nums.sort()
        sum = 0

        for it in nums:
            presum.append(sum)
            sum += it
        
        for i in range(len(nums)-1, 1, -1):
            if nums[i] < presum[i]:
                return presum[i] + nums[i]

        return -1
        