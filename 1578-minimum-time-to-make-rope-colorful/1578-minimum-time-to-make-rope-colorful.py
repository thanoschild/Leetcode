class Solution(object):
    def minCost(self, colors, time):
        ans, max_time, _sum = 0, 0, 0
        for i in range(len(colors)):
            if i > 0 and ord(colors[i]) != ord(colors[i-1]):
                ans += _sum - max_time
                _sum = max_time = 0
            _sum += time[i]
            max_time = max(max_time, time[i])
        ans += _sum - max_time

        return ans
        