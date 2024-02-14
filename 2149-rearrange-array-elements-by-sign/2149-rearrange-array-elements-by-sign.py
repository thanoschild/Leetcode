class Solution(object):
    def rearrangeArray(self, nums):
        n, i, j = len(nums), 0, 1
        ans = [0] * n

        for k in range(n):
            if nums[k] > 0:
                ans[i] = nums[k]
                i += 2
            else:
                ans[j] = nums[k]
                j += 2

        return ans        