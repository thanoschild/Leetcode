class Solution(object):
    def insert(self, intervals, newInterval):
        ans = []
        n, idx = len(intervals), 0

        while idx < n and intervals[idx][1] < newInterval[0]:
            ans.append(intervals[idx])
            idx += 1
        
        while idx < n and intervals[idx][0] <= newInterval[1]:
            newInterval[0] = min(newInterval[0], intervals[idx][0])
            newInterval[1] = max(newInterval[1], intervals[idx][1])
            idx += 1
        
        ans.append(newInterval)

        while idx < n:
            ans.append(intervals[idx])
            idx += 1
        
        return ans

        