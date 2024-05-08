class Solution(object):
    def findRelativeRanks(self, score):
        n = len(score)
        pair = [[0, 0] for _ in range(n)]

        for i in range(n):
            pair[i] = score[i], i
        
        pair.sort(key=lambda x: x[0], reverse=True)
        ans = [''] * n

        for i in range(n):
            if i == 0:
                ans[pair[i][1]] = "Gold Medal"
            elif i == 1:
                ans[pair[i][1]] = "Silver Medal"
            elif i == 2:
                ans[pair[i][1]] = "Bronze Medal"
            else:
                ans[pair[i][1]] = str(i + 1)
        
        return ans

        