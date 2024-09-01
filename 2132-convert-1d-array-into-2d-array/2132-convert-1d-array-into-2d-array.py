class Solution(object):
    def construct2DArray(self, original, m, n):
        length = len(original)
        if n * m != length:
            return []

        ans = []
        idx = 0
        for i in range(m):
            row = []
            for j in range(n):
                row.append(original[idx])
                idx += 1
            ans.append(row)

        return ans
        