class Solution(object):
    def maxCount(self, banned, n, maxSum):
        sum, count = 0, 0
        st = set(banned)

        for i in range(1, n+1):
            if i not in st:
                sum += i
                if sum > maxSum:
                    break
                count += 1
        
        return count
        