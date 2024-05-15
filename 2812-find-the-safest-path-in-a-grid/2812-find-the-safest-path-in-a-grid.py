class Solution(object):
    def maximumSafenessFactor(self, grid):
        n = len(grid)
        dir = [-1, 0, 1, 0, -1]
        
        # BFS to compute distances from all 1's
        pq = deque()
        for i in range(n):
            for j in range(n):
                if grid[i][j] == 1:
                    pq.append((i, j))
        
        while pq:
            i, j = pq.popleft()
            for k in range(4):
                x, y = dir[k] + i, dir[k + 1] + j
                if 0 <= x < n and 0 <= y < n and grid[x][y] == 0:
                    grid[x][y] = grid[i][j] + 1
                    pq.append((x, y))
        
        # Priority queue to find the maximum safeness factor path
        max_heap = []
        heapq.heappush(max_heap, (-grid[0][0], 0, 0))
        grid[0][0] = -1
        
        while True:
            d, i, j = heapq.heappop(max_heap)
            d = -d
            if i == n - 1 and j == n - 1:
                return d - 1
            for k in range(4):
                x, y = i + dir[k], j + dir[k + 1]
                if 0 <= x < n and 0 <= y < n and grid[x][y] != -1:
                    heapq.heappush(max_heap, (-min(d, grid[x][y]), x, y))
                    grid[x][y] = -1
        