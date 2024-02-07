class Solution(object):
    def frequencySort(self, s):
        counter = collections.Counter(s)
        
        heap = [(-freq, char) for char, freq in counter.items()]
        heapq.heapify(heap)
        
        sorted_string = ''
        while heap:
            freq, char = heapq.heappop(heap)
            sorted_string += char * -freq
        
        return sorted_string
        