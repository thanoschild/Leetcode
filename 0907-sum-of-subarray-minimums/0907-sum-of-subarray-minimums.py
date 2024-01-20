class Solution(object):
    def sumSubarrayMins(self, arr):
        n = len(arr)
        st1 = []
        st2 = []
        next = [0] * n
        prev = [0] * n
        ans = 0
        mod = 10**9 + 7

        for i in range(n):
            next[i] = n - i - 1
            prev[i] = i

        for i in range(n):
            while st1 and arr[st1[-1]] > arr[i]:
                next[st1[-1]] = i - st1[-1] - 1
                st1.pop()
            st1.append(i)

        for i in range(n - 1, -1, -1):
            while st2 and arr[st2[-1]] >= arr[i]:
                prev[st2[-1]] = st2[-1] - i - 1
                st2.pop()
            st2.append(i)

        for i in range(n):
            pro = ((next[i] + 1) * (prev[i] + 1)) % mod
            pro = (arr[i] * pro) % mod
            ans = (ans + pro) % mod

        return int(ans)
        