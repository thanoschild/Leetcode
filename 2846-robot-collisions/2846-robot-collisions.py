class Robot:
    def __init__(self, pos, health, direction, index):
        self.position = pos
        self.health = health
        self.direction = direction
        self.index = index

class Solution(object):
    def survivedRobotsHealths(self, positions, healths, directions):
        n = len(positions)
        robots = []
        for i in range(n):
            curr = Robot(positions[i], healths[i], directions[i], i)
            robots.append(curr)

        robots.sort(key=lambda robot: robot.position)

        stack = []
        for robot in robots:
            if robot.direction == 'R':
                stack.append(robot)
                continue

            flag = False
            while stack and stack[-1].health <= robot.health and stack[-1].direction == 'R':
                if stack[-1].health == robot.health:
                    stack.pop()
                    flag = True
                    break
                robot.health -= 1
                stack.pop()

            if not flag and stack and stack[-1].direction == 'R' and stack[-1].health > robot.health:
                stack[-1].health -= 1
                flag = True

            if not flag:
                stack.append(robot)

        stack.sort(key=lambda robot: robot.index)

        ans = [robot.health for robot in stack]
        return ans
        