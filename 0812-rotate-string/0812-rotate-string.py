class Solution(object):
    def rotateString(self, s, goal):
        return len(s) == len(goal) and s in goal + goal
        