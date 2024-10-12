class Solution(object):
    def minGroups(self, intervals):
        intervals.sort()
        pq = []

        for it in intervals:
            if pq and pq[0] < it[0]:
                heapq.heappop(pq)
            heapq.heappush(pq, it[1])
        
        return len(pq)
        