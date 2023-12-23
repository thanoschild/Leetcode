class Solution(object):
    def isPathCrossing(self, path):
        moves = {'E': (1, 0), 'W': (-1, 0), 'N': (0, 1), 'S': (0, -1)}
        visited = set()
        visited.add((0, 0))
        x, y = 0, 0

        for c in path:
            curr = moves[c]
            x += curr[0]
            y += curr[1]

            if (x, y) in visited:
                return True

            visited.add((x, y))
        
        return False
        