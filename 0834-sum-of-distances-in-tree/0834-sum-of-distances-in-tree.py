class Solution(object):
    def __init__(self):
        self.count = []
        self.ans = []

    def dfs(self, adj, root, parent):
        for node in adj[root]:
            if node == parent:
                continue
            self.dfs(adj, node, root)
            self.count[root] += self.count[node]
            self.ans[root] += self.ans[node] + self.count[node]

    def dfs2(self, adj, root, parent):
        for node in adj[root]:
            if node == parent:
                continue
            self.ans[node] = self.ans[root] - self.count[node] + len(self.count) - self.count[node]
            self.dfs2(adj, node, root)

    def sumOfDistancesInTree(self, n, edges):
        self.count = [1] * n
        self.ans = [0] * n

        adj = defaultdict(set)
        for edge in edges:
            adj[edge[0]].add(edge[1])
            adj[edge[1]].add(edge[0])

        self.dfs(adj, 0, -1)
        self.dfs2(adj, 0, -1)
        return self.ans
        