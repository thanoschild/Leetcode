class Solution:
    def __init__(self):
        self.ans = []

    def solve(self, idx, curr, arr, sum):
        if sum == 0:
            self.ans.append(list(curr))  
            return

        for i in range(idx, len(arr)):
            if i > idx and arr[i] == arr[i - 1]:  # Skip duplicates
                continue
            if sum < arr[i]:  
                break

            curr.append(arr[i])
            self.solve(i + 1, curr, arr, sum - arr[i])  
            curr.pop()  

    def combinationSum2(self, arr, target):
        arr.sort()  # Sort the array to handle duplicates
        self.solve(0, [], arr, target)
        return self.ans

        