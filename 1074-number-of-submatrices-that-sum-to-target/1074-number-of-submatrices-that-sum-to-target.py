class Solution(object):
    def numSubmatrixSumTarget(self, mat, target):
        n, m = len(mat), len(mat[0])
        for i in range(n):
            for j in range(1, m):
                mat[i][j] += mat[i][j-1]
        
        ans = 0
        for i in range(m):
            for col in range(i, m):
                mp, _sum = {}, 0
                mp[0] = 1
                for row in range(n):
                    _sum += mat[row][col]
                    _sum -= mat[row][i-1] if i > 0 else 0
                    ans += mp.get(_sum - target, 0)
                    mp[_sum] = mp.get(_sum, 0) + 1
        
        return ans


                
        