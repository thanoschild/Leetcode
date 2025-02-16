class Solution(object):
    def constructDistancedSequence(self, n):
        def backtrack(idx = 0):
            if not unseen: return True
            if ans[idx]: return backtrack(idx+1)

            for num in reversed(range(1, n+1)):
                curr = idx + num if num != 1 else idx
                if num in unseen and curr < (n + n - 1) and not ans[curr]:
                    ans[idx] = ans[curr] = num
                    unseen.remove(num)

                    if backtrack(idx + 1): return True
                    ans[idx] = ans[curr] = 0
                    unseen.add(num)
                
            return False
            
        ans, unseen = [0] * (n + n - 1), set(range(1, n+1))
        backtrack()

        return ans
        