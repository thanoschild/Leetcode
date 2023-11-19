class Graph {
    private List<List<int[]>> graph;

    public Graph(int n, int[][] edges) {
        graph = new ArrayList<>(n);
        for(int i = 0; i<n; i++) {
            graph.add(new ArrayList<>());
        }

        for(int[] edge : edges) {
            addEdge(edge);
        }
    }
    
    public void addEdge(int[] edge) {
        int [] arr = {edge[1], edge[2]};
        graph.get(edge[0]).add(arr);
    }
    
    public int shortestPath(int start, int end) {
        int n = graph.size();
        int[] distance = new int[n];
        Arrays.fill(distance, Integer.MAX_VALUE);
        distance[start] = 0;

        PriorityQueue<int[]> pq = new PriorityQueue<>(Comparator.comparingInt(o->o[0]));
        pq.add(new int[]{0, start});

        while(!pq.isEmpty()) {
            int [] current = pq.poll();
            int node = current[1], dist = current[0];

            if(node == end) return dist;

            for(int[] edge : graph.get(node)) {
                int curr_node = edge[0];
                int curr_dist = edge[1] + dist;

                if(curr_dist < distance[curr_node]) {
                    distance[curr_node] = curr_dist;
                    pq.add(new int[] {curr_dist, curr_node});
                }
            }
        }

        return (distance[end] == Integer.MAX_VALUE) ? -1 : distance[end];
    }
}

/**
 * Your Graph object will be instantiated and called as such:
 * Graph obj = new Graph(n, edges);
 * obj.addEdge(edge);
 * int param_2 = obj.shortestPath(node1,node2);
 */