class Solution(object):
    def generate(self, numRows):
        ans = []
        for i in range(0, numRows):
            v = [1]*(i+1)
            for j in range(1, i):
                v[j] = ans[i-1][j] + ans[i-1][j-1]
            
            ans.append(v)
        
        return ans
        