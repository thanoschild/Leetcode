class Solution(object):
    def solve(self, img, x, y):
        n, m = len(img), len(img[0])
        _sum, count = 0, 0
        
        for i in range(-1, 2):
            for j in range(-1, 2):
                dx = i + x
                dy = j + y
                if dx >= 0 and dx < n and dy >= 0 and dy < m:
                    _sum += img[dx][dy]
                    count += 1
                    
        return _sum//count
    
    def imageSmoother(self, img):
        n, m = len(img), len(img[0])
        ans = [[0] * m for _ in range(n)]
        
        for i in range(n):
            for j in range(m):
                ans[i][j] = self.solve(img, i, j)
        
        return ans
        