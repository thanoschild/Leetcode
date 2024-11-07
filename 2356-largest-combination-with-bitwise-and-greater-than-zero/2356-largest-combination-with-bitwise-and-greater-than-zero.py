class Solution(object):
    def largestCombination(self, candidates):
        ans, i = 0, 1
        while i <= 10000000:
            curr = 0
            for n in candidates:
                if n & i > 0:
                    curr += 1
            ans = max(ans, curr)
            i = i << 1
        
        return ans