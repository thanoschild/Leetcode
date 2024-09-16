class Solution(object):
    def findMinDifference(self, timePoints):
        seen = [False] * (24 * 60)
        maxMin = float('-inf')
        minMin = float('inf')

        for s in timePoints:
            h, m = map(int, s.split(":"))
            totalMinutes = h * 60 + m

            if seen[totalMinutes]:
                return 0

            maxMin = max(maxMin, totalMinutes)
            minMin = min(minMin, totalMinutes)
            seen[totalMinutes] = True

        diff = float('inf')
        prev = None

        for i in range(minMin, maxMin + 1):
            if seen[i]:
                if prev is None:
                    diff = min(diff, min(maxMin - minMin, 1440 - maxMin + minMin))
                else:
                    diff = min(diff, i - prev)
                prev = i

        return diff
        