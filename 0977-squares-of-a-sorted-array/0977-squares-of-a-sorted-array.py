class Solution(object):
    def sortedSquares(self, nums):
        n = len(nums)
        left, right = 0, n - 1
        ans = [0]*n

        for i in range(n-1, -1, -1):
            if abs(nums[left]) >= abs(nums[right]):
                ans[i] = nums[left]*nums[left]
                left += 1
            else:
                ans[i] = nums[right]*nums[right]
                right -= 1
            
        return ans
        