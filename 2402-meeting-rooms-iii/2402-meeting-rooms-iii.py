class Solution(object):
    def mostBooked(self, n, meet):
        ans = [0] * n
        time = [0] * n
        meet.sort(key=lambda x: x[0])

        for meeting in meet:
            start, end = meeting
            min_val = float('inf')
            idx = -1
            flag = True

            for j in range(n):
                if min_val > time[j]:
                    min_val = time[j]
                    idx = j

                if start >= time[j]:
                    time[j] = end
                    ans[j] += 1
                    flag = False
                    break

            if flag:
                ans[idx] += 1
                time[idx] += (end - start)

        max_count = -1
        max_idx = -1
        for i in range(n):
            if ans[i] > max_count:
                max_count = ans[i]
                max_idx = i

        return max_idx
        