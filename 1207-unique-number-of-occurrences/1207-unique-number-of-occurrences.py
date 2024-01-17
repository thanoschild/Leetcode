class Solution(object):
    def uniqueOccurrences(self, arr):
        arr.sort()
        i, n = 0, len(arr)
        ans = []

        while i < n:
            count, j = 1, i+1
            while j < n:
                if arr[i] == arr[j]: count += 1
                else: break
                j += 1
            ans.append(count)
            i = j
        
        ans.sort()
        for i in range(0, len(ans) - 1):
            if ans[i] == ans[i+1]: return False

        return True
        