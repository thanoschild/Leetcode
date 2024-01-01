class Solution(object):
    def isReachableAtTime(self, sx, sy, fx, fy, t):
        diff_x = abs(sx - fx)
        diff_y = abs(sy - fy)

        if diff_x == 0 and diff_y == 0:
            return t != 1

        return diff_x <= t and diff_y <= t
        