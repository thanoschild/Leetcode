class Solution(object):
    def __init__(self):
        self.count = []

    def merge(self, arr, left, mid, right):
        n1 = mid - left + 1
        n2 = right - mid

        arr1 = arr[left:mid+1]
        arr2 = arr[mid+1:right+1]

        p = 0
        q = 0
        r = left

        while p < n1 and q < n2:
            if arr1[p][0] <= arr2[q][0]:
                self.count[arr1[p][1]] += q
                arr[r] = arr1[p]
                r += 1
                p += 1
            else:
                arr[r] = arr2[q]
                r += 1
                q += 1

        while p < n1:
            arr[r] = arr1[p]
            self.count[arr1[p][1]] += q
            r += 1
            p += 1

        while q < n2:
            arr[r] = arr2[q]
            r += 1
            q += 1

    def mergeSort(self, arr, left, right):
        if left < right:
            mid = (right - left) // 2 + left
            self.mergeSort(arr, left, mid)
            self.mergeSort(arr, mid + 1, right)
            self.merge(arr, left, mid, right)

    def countSmaller(self, nums):
        n = len(nums)
        self.count = [0] * n

        arr = [(nums[i], i) for i in range(n)]

        self.mergeSort(arr, 0, n - 1)

        return self.count
        