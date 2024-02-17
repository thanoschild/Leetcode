class Solution(object):
    def furthestBuilding(self, heights, bricks, ladders):
        n = len(heights)
        i = 0
        pq = []
        while i < n - 1:
            diff = heights[i+1] - heights[i]
            if diff < 0:
                i += 1
                continue
            elif diff <= bricks:
                bricks -= diff
                heapq.heappush(pq, -diff)
                i += 1
            elif ladders > 0:
                if pq and -pq[0] > diff:
                    bricks += -heapq.heappop(pq)
                    bricks -= diff
                    heapq.heappush(pq, -diff)
                ladders -= 1
                i += 1
            else:
                break
        return i
        