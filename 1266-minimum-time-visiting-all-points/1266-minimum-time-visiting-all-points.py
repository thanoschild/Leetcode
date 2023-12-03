class Solution(object):
    def minTimeToVisitAllPoints(self, points):
        ans, n = 0, len(points)
        for i in range(1, n):
            curr, prev = points[i], points[i-1]
            ans += max(abs(curr[0] - prev[0]), abs(curr[1]-prev[1]))
        return ans
        