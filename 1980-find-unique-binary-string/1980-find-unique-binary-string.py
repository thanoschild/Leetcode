class Solution(object):
    def findDifferentBinaryString(self, nums):
        ans = ''
        for i in range(len(nums)):
            curr = nums[i][i]
            if curr == '0':
                opp = '1'
            else:
                opp = '0'
            ans += opp
            
        return ans
        