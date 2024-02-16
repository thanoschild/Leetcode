class Solution(object):
    def findLeastNumOfUniqueInts(self, arr, k):
        mp = list(collections.Counter(arr).values())
        heapq.heapify(mp)
        while k > 0:
            k -= heapq.heappop(mp)
        return len(mp) + (k < 0)