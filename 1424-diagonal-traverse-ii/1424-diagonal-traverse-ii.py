class Solution(object):
    def findDiagonalOrder(self, nums):
        n = len(nums)
        m = 0
        mp = {}

        for i in range(n):
            k = len(nums[i])
            m = max(m, k)
            for j in range(k):
                if (i + j) in mp:
                    mp[i + j].append(nums[i][j])
                else:
                    mp[i + j] = [nums[i][j]]

        ans = []
        for i in range(n + m - 1):
            temp = mp.get(i, [])
            for j in range(len(temp) - 1, -1, -1):
                ans.append(temp[j])

        return ans
        