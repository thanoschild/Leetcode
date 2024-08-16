class Solution(object):
    def maxDistance(self, arrays):
        mx = arrays[0][-1]  
        mn = arrays[0][0]   
        diff = 0

        for i in range(1, len(arrays)):
            curr_max = arrays[i][-1]
            curr_min = arrays[i][0]

            diff = max(diff, abs(mx - curr_min))
            diff = max(diff, abs(curr_max - mn))

            mx = max(mx, curr_max)
            mn = min(mn, curr_min)

        return diff
        