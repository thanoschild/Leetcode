class Solution(object):
    def dfs(self, curr, n, ans):
        if curr > n:
            return
        ans.append(curr)
        for i in range(0, 10):
            if 10 * curr + i > n:
                return
            self.dfs(10 * curr + i, n, ans)
        
    def lexicalOrder(self, n):
        ans = []
        for i in range(1, 10):
            self.dfs(i, n, ans)
        
        return ans
        