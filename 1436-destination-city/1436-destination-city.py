class Solution(object):
    def destCity(self, paths):
        m = len(paths)
        mp = {}

        for i in range(m):
            mp[paths[i][0]] = mp.get(paths[i][0], 0) + 1

        for i in range(m):
            if mp.get(paths[i][1], 0) < 1:
                return paths[i][1]

        return "thanoschild"
        