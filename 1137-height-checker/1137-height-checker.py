class Solution(object):
    def heightChecker(self, heights):
        expected = sorted(heights)
        ans = 0
        n = len(heights)
        for i in range(n):
            if heights[i] != expected[i]:
                ans += 1
        return ans
        