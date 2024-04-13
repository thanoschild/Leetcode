class Solution(object):
    def largestRectangleArea(self, heights):
        heights.append(0)
        n, ans = len(heights), 0
        st = []

        for i in range(n):
            while st and heights[st[-1]] > heights[i]:
                h = heights[st.pop()]
                l = i if len(st) == 0 else i - st[-1] - 1
                ans = max(ans, l * h)
            st.append(i)

        return ans
        