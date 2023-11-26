class Solution(object):
    def largestSubmatrix(self, mat):
        n, m = len(mat), len(mat[0])
        for i in range(1, n):
            for j in range(m):
                if mat[i][j] == 1:
                    mat[i][j] += mat[i-1][j]
                    
        ans = 0
        for v in mat:
            v.sort()
            k = 1
            for x in v[::-1]:
                if x > 0:
                    ans = max(ans, x*k)
                k += 1
                
        return ans
                
        