class Solution(object):
    def trap(self, height):
        n = len(height)
        stack = []
        ans = 0

        for i in range(n):
            while stack and height[stack[-1]] < height[i]:
                t = stack[-1]
                stack.pop()
                if len(stack) == 0:
                    break
                h = min(height[i], height[stack[-1]]) - height[t]
                l = i - stack[-1] - 1
                ans += (l * h)
            stack.append(i)

        return ans

        