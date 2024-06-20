class Solution(object):
    def maxDistance(self, position, m):
        position.sort()
        n = len(position)
        left, right, ans = 0, position[-1], 0

        while left <= right:
            mid = (right + left)/2
            curr, count = position[0], 1
            for i in range(1, n):
                if position[i] - curr >= mid:
                    count += 1
                    curr = position[i]
            
            if count >= m:
                ans = mid
                left = mid + 1
            else:
                right = mid - 1
        
        return ans
        