class Solution(object):
    def maxScoreSightseeingPair(self, values):
        ans, curr = float('-inf'), values[0]

        for i in range(1, len(values)):
            ans = max(ans, curr + values[i] - i)
            curr = max(curr, values[i] + i)
        
        return ans
        