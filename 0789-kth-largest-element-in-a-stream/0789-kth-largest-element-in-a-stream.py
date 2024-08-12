class KthLargest(object):

    def __init__(self, k, nums):
        self.limit = k
        self.pq = nums
        heapq.heapify(self.pq)
        while len(self.pq) > self.limit:
            heapq.heappop(self.pq)
        

    def add(self, val):
        heapq.heappush(self.pq, val)
        if len(self.pq) > self.limit:
            heapq.heappop(self.pq)
        return self.pq[0]
        


# Your KthLargest object will be instantiated and called as such:
# obj = KthLargest(k, nums)
# param_1 = obj.add(val)