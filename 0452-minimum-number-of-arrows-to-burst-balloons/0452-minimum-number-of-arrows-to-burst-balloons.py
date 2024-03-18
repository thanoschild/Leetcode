class Solution(object):
    def findMinArrowShots(self, points):
        n = len(points)
        if n == 0:
            return 0

        points.sort(key = lambda x : x[1])
        arrows, arrowPos = 1, points[0][1]

        for i in range(1, n):
            if arrowPos >= points[i][0]:
                continue
            arrows += 1
            arrowPos = points[i][1]
        
        return arrows
        