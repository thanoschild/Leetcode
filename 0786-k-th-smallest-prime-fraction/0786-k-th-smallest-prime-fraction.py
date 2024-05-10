class Solution(object):
    def find_position(self, arr, mid):
        j, total, num, den, n = 1, 0, 0, 0, len(arr)
        frac = 0.0

        for i in range(n):
            while j < n and arr[i] >= arr[j] * mid:
                j += 1
            total += n - j

            if j < n and frac < arr[i] * 1.0 / arr[j]:
                frac = arr[i] * 1.0 / arr[j]
                num, den = i, j

        return [total, num, den]
            
    def kthSmallestPrimeFraction(self, arr, k):
        n = len(arr)
        left, right = 0, 1.0
        ans = []

        while left <= right:
            mid = (right - left) / 2 + left
            pos = self.find_position(arr, mid)
            if pos[0] == k:
                ans = [arr[pos[1]], arr[pos[2]]]
                break

            if pos[0] > k:
                right = mid
            else:
                left = mid

        return ans
        