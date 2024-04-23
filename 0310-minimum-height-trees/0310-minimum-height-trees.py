class Solution(object):
    def findMinHeightTrees(self, n, edges):
        if n == 0:
            return []
        elif n == 1:
            return [0]

        adj = [[] for _ in range(n)]
        indegree = [0] * n

        for u, v in edges:
            adj[u].append(v)
            adj[v].append(u)
            indegree[u] += 1
            indegree[v] += 1

        ans = []
        pq = deque()
        for i in range(n):
            if indegree[i] == 1:
                pq.append(i)

        while pq:
            ans = []
            length = len(pq)
            for _ in range(length):
                curr = pq.popleft()
                ans.append(curr)

                for neighbor in adj[curr]:
                    indegree[neighbor] -= 1
                    if indegree[neighbor] == 1:
                        pq.append(neighbor)

        return ans
        