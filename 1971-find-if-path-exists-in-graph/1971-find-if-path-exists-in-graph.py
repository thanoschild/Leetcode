class Solution(object):
    def dfs(self, edges, seen, idx, dest):
        seen[idx] = True
        if seen[dest]:
            return
        
        for edge in edges[idx]:
            if seen[edge] == False:
                self.dfs(edges, seen, edge, dest)

                
    def validPath(self, n, edges, source, destination):
        seen = [False] * n
        adj = [[] for _ in range(n)]

        for edge in edges:
            adj[edge[0]].append(edge[1])
            adj[edge[1]].append(edge[0])
        
        self.dfs(adj, seen, source, destination)
        return seen[destination]
        