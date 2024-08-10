class Solution(object):
    def __init__(self):
        self.parent = []
        self.sz = []

    def find_set(self, x):
        if self.parent[x] == x:
            return x
        self.parent[x] = self.find_set(self.parent[x])  # Path compression
        return self.parent[x]

    def make_union(self, x, y):
        a = self.find_set(x)
        b = self.find_set(y)
        if a == b:
            return True

        if self.sz[b] > self.sz[a]:
            a, b = b, a  # Swap to ensure the larger set is the parent

        self.parent[b] = a
        self.sz[a] += self.sz[b]
        return False

    def regionsBySlashes(self, grid):
        n = len(grid) + 1
        self.parent = [i for i in range(n * n)]
        self.sz = [1] * (n * n)

        for i in range(n):
            for j in range(n):
                if i == 0 or j == 0 or i == n - 1 or j == n - 1:
                    x = i * n + j
                    self.make_union(0, x)

        ans = 1
        for i in range(len(grid)):
            s = grid[i]
            for j in range(len(s)):
                c = s[j]
                if c == '/':
                    x = (i + 1) * n + j
                    y = i * n + (j + 1)
                    if self.make_union(x, y):
                        ans += 1
                elif c == '\\':
                    x = i * n + j
                    y = (i + 1) * n + (j + 1)
                    if self.make_union(x, y):
                        ans += 1

        return ans
        