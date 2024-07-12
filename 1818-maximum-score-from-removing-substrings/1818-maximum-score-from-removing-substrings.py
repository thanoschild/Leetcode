class Solution(object):
    def maximumGain(self, s, x, y):
        if x > y:
            top, top_score = "ab", x
            bot, bot_score = "ba", y
        else:
            top, top_score = "ba", y
            bot, bot_score = "ab", x

        stack = []
        ans = 0
        for c in s:
            if c == top[1] and stack and stack[-1] == top[0]:
                ans += top_score
                stack.pop()
            else:
                stack.append(c)

        stack1 = []
        for c in stack:
            if c == bot[1] and stack1 and stack1[-1] == bot[0]:
                ans += bot_score
                stack1.pop()
            else:
                stack1.append(c)

        return ans
        