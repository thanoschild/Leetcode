from collections import defaultdict
import math

class Solution(object):
    def longestSquareStreak(self, nums):
        n = len(nums)
        ans = 0
        mp = defaultdict(int)
        nums.sort()

        for it in nums:
            root = int(math.sqrt(it))
            if root * root == it:
                mp[it] = mp.get(root, 0) + 1
            else:
                mp[it] = 1
            ans = max(ans, mp[it])
        
        return -1 if ans < 2 else ans
        