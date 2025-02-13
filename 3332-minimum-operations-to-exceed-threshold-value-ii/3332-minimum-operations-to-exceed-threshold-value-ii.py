import heapq

class Solution(object):
    def minOperations(self, nums, k):
        pq, ops = [], 0
        for it in nums:
            if it < k:
                heapq.heappush(pq, it)
        
        while pq:
            x = heapq.heappop(pq)
            ops += 1

            if len(pq) == 0:
                break
            
            y = heapq.heappop(pq)
            val = 2 * x + y

            if val < k:
                heapq.heappush(pq, val)
        
        return ops
        
        