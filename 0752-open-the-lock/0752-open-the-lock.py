class Solution(object):
    def possible_ways(self, s):
        ways = []
        for i in range(4):
            curr = list(s)
            if curr[i] == '9':
                curr[i] = '0'
            else:
                curr[i] = str(int(curr[i]) + 1)
            ways.append(''.join(curr))

            curr = list(s)
            if curr[i] == '0':
                curr[i] = '9'
            else:
                curr[i] = str(int(curr[i]) - 1)
            ways.append(''.join(curr))
        return ways
            
    def openLock(self, deadends, target):
        if target == '0000':
            return 0
        check, visited, ans = set(deadends), set(), 0
        pq = deque(["0000"])

        while pq:
            n = len(pq)
            for i in range(n):
                curr = pq.popleft()

                if curr == target:
                    return ans
                if curr in check or curr in visited:
                    continue
                
                ways = self.possible_ways(curr)
                pq.extend(ways)
                visited.add(curr)
            ans += 1
        
        return -1

        