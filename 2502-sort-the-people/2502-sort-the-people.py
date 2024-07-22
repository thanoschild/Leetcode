class Solution(object):
    def sortPeople(self, names, heights):
        mp = {}
        for i in range(len(names)):
            mp[heights[i]] = names[i]

        ans = []
        for height in sorted(mp.keys(), reverse=True):
            ans.append(mp[height])

        return ans
        