class Solution(object):
    def maxWidthOfVerticalArea(self, points):
        points.sort(key = lambda x : x[0])
        ans = 0
        
        for i in range(1, len(points)):
            ans = max(ans, points[i][0] - points[i-1][0])
            
        return ans
        