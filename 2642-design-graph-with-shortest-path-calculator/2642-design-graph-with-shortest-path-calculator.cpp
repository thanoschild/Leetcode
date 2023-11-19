class Graph {
public:
    vector<vector<pair<int,int>>> adj;
    Graph(int n, vector<vector<int>>& edges) {
        adj.resize(n);
        for(auto edge : edges) {
           adj[edge[0]].push_back({edge[1], edge[2]});
        }
    }
    
    void addEdge(vector<int> edge) {
        adj[edge[0]].push_back({edge[1], edge[2]});
    }
    
    int shortestPath(int start, int end) {
        int n = adj.size();
        vector<int> distance(n, INT_MAX);
        distance[start] = 0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
        pq.push({0, start});

        while(!pq.empty()) {
            int cost = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for(auto edge : adj[node]) {
                int curr_node = edge.first;
                int curr_cost = edge.second + cost;
                if(distance[curr_node] > curr_cost) {
                    distance[curr_node] = curr_cost;
                    pq.push({curr_cost, curr_node});
                }
            }
        }

        return (distance[end] == INT_MAX) ? -1 : distance[end];
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */