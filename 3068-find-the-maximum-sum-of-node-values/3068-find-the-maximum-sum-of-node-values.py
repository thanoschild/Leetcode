class Solution(object):
    def maximumValueSum(self, nums, k, edges):
        delta = [(n ^ k) - n for n in nums]
        delta.sort(reverse = True)

        ans = sum(nums)
        for i in range(0, len(nums), 2):
            if i == len(nums) - 1:
                break
            curr_delta = delta[i] + delta[i+1]
            if curr_delta <= 0:
                break
            ans += curr_delta
        
        return ans
        