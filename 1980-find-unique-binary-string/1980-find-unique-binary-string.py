class Solution(object):
    def findDifferentBinaryString(self, nums):
        ans = ''
        for i in range(len(nums)):
            curr = nums[i][i]
            opp = '1' if curr == '0' else '0'
            ans += opp
            
        return ans
        