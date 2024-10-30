class Solution(object):
    def minimumMountainRemovals(self, nums):
        n = len(nums)
        left, right = [1] * n, [1] * n

        for i in range(1, n):
            for j in range(i):
                if nums[i] > nums[j]:
                    left[i] = max(left[i], 1 + left[j])
        
        for i in range(n-2, -1, -1):
            for j in range(n-1, i, -1):
                if nums[i] > nums[j]:
                    right[i] = max(right[i], 1 + right[j])

        max_len = 0
        for i in range(1, n-1):
            if left[i] > 1 and right[i] > 1:
                max_len = max(max_len , left[i] + right[i] - 1)
        
        return n - max_len
        