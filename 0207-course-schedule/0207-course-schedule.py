class Solution(object):
    def canFinish(self, numCourses, prerequisites):
        indegree = [0] * numCourses
        adj = [[] for _ in range(numCourses)]
        
        for prereq in prerequisites:
            adj[prereq[1]].append(prereq[0])
            indegree[prereq[0]] += 1

        queue = deque()
        for i in range(numCourses):
            if indegree[i] == 0:
                queue.append(i)

        count = 0
        while queue:
            course = queue.popleft()
            count += 1
            for next_course in adj[course]:
                indegree[next_course] -= 1
                if indegree[next_course] == 0:
                    queue.append(next_course)

        return count == numCourses
        