class UnionFind:
    def __init__(self, n):
        self.parent = list(range(n))
        self.sz = [1] * n

    def find_parent(self, x):
        if x == self.parent[x]:
            return x
        self.parent[x] = self.find_parent(self.parent[x])
        return self.parent[x]

    def make_union(self, x, y):
        a = self.find_parent(x)
        b = self.find_parent(y)
        if a != b:
            if self.sz[b] > self.sz[a]:
                a, b = b, a
            self.parent[b] = a
            self.sz[a] += self.sz[b]

    def reset(self, x):
        self.parent[x] = x


class Solution(object):
    def findAllPeople(self, n, meet, firstPerson):
        uf = UnionFind(n)
        meet.sort(key=lambda x: x[2])
        people = []
        m = len(meet)
        uf.make_union(0, firstPerson)

        i = 0
        while i < m:
            people = []
            time = meet[i][2]
            while i < m and meet[i][2] == time:
                a, b = meet[i][0], meet[i][1]
                uf.make_union(a, b)
                people.extend([a, b])
                i += 1

            for x in people:
                if uf.find_parent(x) != uf.find_parent(0):
                    uf.reset(x)

        ans = [i for i in range(n) if uf.find_parent(0) == uf.find_parent(i)]
        return ans
        