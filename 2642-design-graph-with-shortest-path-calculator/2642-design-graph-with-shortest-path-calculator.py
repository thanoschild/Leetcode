class Graph(object):

    def __init__(self, n, edges):
        self.node = n
        self.graph = [[] for _ in range(n)]
        for edge in edges:
            self.graph[edge[0]].append((edge[1], edge[2]))
        

    def addEdge(self, edge):
        self.graph[edge[0]].append((edge[1], edge[2]))
        

    def shortestPath(self, start, end):
        distance = [10**9]*self.node
        distance[start] = 0
        pq = [(0, start)] 

        while pq:
            dist, node = heapq.heappop(pq)

            for curr_node, curr_dist in self.graph[node]:
                total_dist = curr_dist + dist
                if distance[curr_node] > total_dist:
                    distance[curr_node] = total_dist
                    heapq.heappush(pq, (total_dist, curr_node))

        print(distance)
        return distance[end] if distance[end] != 10**9 else -1
            

        


# Your Graph object will be instantiated and called as such:
# obj = Graph(n, edges)
# obj.addEdge(edge)
# param_2 = obj.shortestPath(node1,node2)