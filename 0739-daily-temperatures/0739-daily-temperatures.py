class Solution(object):
    def dailyTemperatures(self, temp):
        n = len(temp)
        ans = [0]*n
        st = []
        
        for i in range(n-1, -1, -1):
            while st and temp[st[-1]] <= temp[i]: st.pop()
            if st: ans[i] = st[-1] - i
            st.append(i)
        
        return ans