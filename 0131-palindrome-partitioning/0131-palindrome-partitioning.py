class Solution(object):
    def check(self, s, i, j):
        while i < j:
            if s[i] != s[j]:
                return False
            i += 1
            j -= 1
        return True

    def solve(self, s, idx, curr, ans):
        n = len(s)
        if idx == n:
            ans.append(list(curr))
            return

        for i in range(idx, n):
            if self.check(s, idx, i):
                curr.append(s[idx:i + 1])
                self.solve(s, i + 1, curr, ans)
                curr.pop()

    def partition(self, s):
        ans = []
        if len(s) == 0:
            return ans
        curr = []
        self.solve(s, 0, curr, ans)
        return ans
        