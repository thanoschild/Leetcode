class Solution(object):
    def subsets(self, nums):
        n = len(nums)
        ans = []
        for i in range(0, (1 << n)):
            curr = []
            for j in range(0, n):
                if (i & (1 << j)) > 0:
                    curr.append(nums[j])
            ans.append(curr)
        return ans
        