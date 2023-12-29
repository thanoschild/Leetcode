class Solution(object):
    def restoreArray(self, nums):
        map = defaultdict(list)

        for it in nums:
            map[it[0]].append(it[1])
            map[it[1]].append(it[0])

        start = float('-inf')
        for key, value in map.items():
            if len(value) == 1:
                start = key
                break

        prev = float('-inf')
        ans = []
        ans.append(start)

        for i in range(len(nums)):
            v = map[start]
            curr = v[1] if prev == v[0] else v[0]
            ans.append(curr)
            prev = start
            start = curr

        return ans
        