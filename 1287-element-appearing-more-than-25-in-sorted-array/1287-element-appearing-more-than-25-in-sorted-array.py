class Solution(object):
    def findSpecialInteger(self, arr):
        count, n = 1, len(arr)
        if n == 1:
            return arr[0]
        
        for i in range(1, n):
            if arr[i] == arr[i-1]:
                count += 1
            else:
                count = 1
            
            if count > n//4:
                return arr[i]
        
        return -1
        