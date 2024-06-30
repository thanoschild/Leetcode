class UnionFind:
    def __init__(self, n):
        self.parent = list(range(n))
        self.sz = [1] * n

    def findSet(self, x):
        if self.parent[x] != x:
            self.parent[x] = self.findSet(self.parent[x])
        return self.parent[x]

    def makeUnion(self, x, y):
        a = self.findSet(x)
        b = self.findSet(y)
        if a == b:
            return 0
        if self.sz[a] < self.sz[b]:
            a, b = b, a
        self.sz[a] += self.sz[b]
        self.parent[b] = a
        return 1

    def count(self, x):
        root = self.findSet(x)
        return self.sz[root]

class Solution(object):
    def maxNumEdgesToRemove(self, n, edges):
        alice = []
        bob = []
        both = []

        for t, x, y in edges:
            x -= 1
            y -= 1
            if t == 3:
                both.append((x, y))
            elif t == 2:
                bob.append((x, y))
            else:
                alice.append((x, y))

        a = UnionFind(n)
        b = UnionFind(n)
        requiredEdges = 0

        for x, y in both:
            requiredEdges += a.makeUnion(x, y)
            b.makeUnion(x, y)

        for x, y in alice:
            requiredEdges += a.makeUnion(x, y)

        for x, y in bob:
            requiredEdges += b.makeUnion(x, y)

        if a.count(0) < n or b.count(0) < n:
            return -1

        return len(edges) - requiredEdges
        