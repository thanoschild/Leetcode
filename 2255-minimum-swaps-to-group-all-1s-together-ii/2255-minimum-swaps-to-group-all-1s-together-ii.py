class Solution(object):
    def minSwaps(self, nums):
        n = len(nums)
        ones = 0
        zeros = 0

        for i in range(n):
            if nums[i] == 1:
                ones += 1

        for i in range(ones):
            if nums[i] == 0:
                zeros += 1

        min_swaps = zeros
        for i in range(1, n):
            start = i
            end = (i + ones - 1) % n
            if nums[start - 1] == 0:
                zeros -= 1
            if nums[end] == 0:
                zeros += 1
            min_swaps = min(min_swaps, zeros)

        return min_swaps
        