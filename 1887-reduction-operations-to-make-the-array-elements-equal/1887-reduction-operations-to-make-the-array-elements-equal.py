class Solution(object):
    def reductionOperations(self, nums):
        count, prev, n = 0, 0, len(nums)
        nums.sort()
        
        for i in range(1, n):
            if nums[i] == nums[i-1]:
                if prev == 0: continue
                else: count += prev
            else:
                prev += 1
                count += prev
                
        return count
            
        