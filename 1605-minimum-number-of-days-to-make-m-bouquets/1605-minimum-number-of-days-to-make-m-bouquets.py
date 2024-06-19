class Solution(object):
    def minDays(self, bloomDay, m, k):
        left, right, ans = 0, 10**9, -1

        while left <= right:
            mid = (right + left)/2
            con, buk = 0, 0
            for n in bloomDay:
                if n <= mid:
                    con += 1
                    if con >= k:
                        buk += 1
                        con = 0
                else:
                    con = 0
            
            if buk >= m:
                ans = mid
                right = mid - 1
            else:
                left = mid + 1
        
        return ans
        