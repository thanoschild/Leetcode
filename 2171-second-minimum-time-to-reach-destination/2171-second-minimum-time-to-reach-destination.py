class Solution(object):
    def secondMinimum(self, n, edges, time, change):
        adj = defaultdict(list)
        for it in edges:
            adj[it[0]].append(it[1])
            adj[it[1]].append(it[0])
        
        pq = deque([(1, 0)])
        visitedTime = [0] * (n+1)
        visited = [0] * (n+1)
        firstVisited = float('inf')

        while pq:
            node, t = pq.popleft()
            for next_node in adj[node]:
                t2 = t
                isRed = (t2 // change) % 2
                if isRed == 1:
                    t2 += change - (t2 % change)
                t2 += time
            
                if next_node == n and firstVisited == float('inf'):
                    firstVisited = t2
                if next_node == n and t2 > firstVisited:
                    return t2
                if visitedTime[next_node] != t2 and visited[next_node] <= 1:
                    visited[next_node] += 1
                    visitedTime[next_node] = t2
                    pq.append((next_node, t2))
                
        return -1


        