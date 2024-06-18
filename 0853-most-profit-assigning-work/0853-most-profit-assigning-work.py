class Solution(object):
    def maxProfitAssignment(self, difficulty, profit, worker):
        jobs = list(zip(difficulty, profit))
        jobs.sort(key=lambda x: (x[0], -x[1]))
        worker.sort()

        ans = 0
        idx = 0
        curr = 0
        n = len(jobs)
        m = len(worker)
        for i in range(m):
            while idx < n and jobs[idx][0] <= worker[i]:
                curr = max(curr, jobs[idx][1])
                idx += 1
            ans += curr

        return ans
        