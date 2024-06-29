class Solution(object):

    def dfs(self, x, curr, ans, child):
        for it in child[curr]:
            if len(ans[it]) == 0 or ans[it][-1] != x:
                ans[it].append(x)
                self.dfs(x, it, ans, child)

    def getAncestors(self, n, edges):
        ans = [[] for _ in range(n)]
        child = defaultdict(list)

        for e in edges:
            child[e[0]].append(e[1])

        for i in range(n):
            self.dfs(i, i, ans, child)

        return ans
        