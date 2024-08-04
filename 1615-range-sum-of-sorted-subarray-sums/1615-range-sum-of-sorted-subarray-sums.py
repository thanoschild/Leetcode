class Solution(object):
    def rangeSum(self, nums, n, left, right):
        pq = []
        for i in range(n):
            heapq.heappush(pq, (nums[i], i + 1))

        ans = 0
        mod = 10**9 + 7
        for i in range(1, right + 1):
            t = heapq.heappop(pq)
            if i >= left:
                ans = (ans + t[0]) % mod
            if t[1] < n:
                new_pair = (t[0] + nums[t[1]], t[1] + 1)
                heapq.heappush(pq, new_pair)

        return ans
            