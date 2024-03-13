class Solution(object):
    def find_sum(self, n):
        return n * (n + 1)//2

    def pivotInteger(self, n):
        left, right = 1, n
        while left <= right:
            mid = (right - left)//2 + left
            x = self.find_sum(mid)
            y = self.find_sum(n) - x + mid
            if x == y:
                return mid
            if x > y:
                right = mid - 1
            else:
                left = mid + 1
            
        return -1
        