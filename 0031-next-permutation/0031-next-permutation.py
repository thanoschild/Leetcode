class Solution(object):
    def nextPermutation(self, nums):
        n = len(nums)
        flag = True
        for i in range(n-2, -1, -1):
            if nums[i] < nums[i+1]:
                flag = False
                nums[i+1:] = sorted(nums[i+1:])
                k = i + 1
                while nums[i] >= nums[k]:
                    k = k + 1
                nums[k], nums[i] = nums[i], nums[k]
                break
        
        if flag:
            nums.sort()
        