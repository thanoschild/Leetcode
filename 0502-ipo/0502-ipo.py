class Solution(object):
    def my_compare(a, b):
        if a[0] == b[0]:
            return a[1] > b[1]
        return a[0] < b[0]
        
    def findMaximizedCapital(self, k, w, profits, capital):
        n = len(profits)
        projects = [(capital[i], profits[i]) for i in range(n)]
        projects.sort(key=lambda x: (x[0], -x[1]))

        idx = 0
        max_heap = []
        while k > 0:
            while idx < n and projects[idx][0] <= w:
                heapq.heappush(max_heap, -projects[idx][1])
                idx += 1
            
            if max_heap:
                w += -heapq.heappop(max_heap)
            k -= 1

        return w
        