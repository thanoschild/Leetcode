class Solution(object):
    def robotSim(self, commands, obstacles):
        st = set()
        for obs in obstacles:
            st.add("{}-{}".format(obs[0], obs[1]))

        dirs = [(0, 1), (1, 0), (0, -1), (-1, 0)]
        d, x, y, ans = 0, 0, 0, 0

        for c in commands:
            if c == -1:
                d = (d + 1) % 4
            elif c == -2:
                d = (d - 1 + 4) % 4
            else:
                while c > 0 and "{}-{}".format(x + dirs[d][0], y + dirs[d][1]) not in st:
                    x += dirs[d][0]
                    y += dirs[d][1]
                    c -= 1
            ans = max(ans, x*x + y*y)

        return ans