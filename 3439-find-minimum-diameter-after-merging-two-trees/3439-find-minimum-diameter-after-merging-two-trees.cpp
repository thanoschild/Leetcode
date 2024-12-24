class Solution {
public:
    int findDiameter(vector<vector<int>> &edges) {
        int n = edges.size() + 1;
        vector<vector<int>> adj(n);
        vector<int> degree(n, 0);

        for(auto &edge : edges) {
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            degree[u]++;
            degree[v]++;
        }

        queue<int> pq;
        for(int i = 0; i<n; i++) {
            if(degree[i] == 1) pq.push(i);
        }

        int level = 0, left = n;
        while(left > 2) {
            int len = pq.size();
            left -= len;
            for(int i = 0; i<len; i++) {
                int t = pq.front();
                pq.pop();
                for(int node : adj[t]) {
                    degree[node]--;
                    if(degree[node] == 1) pq.push(node);
                }
            }
            level++;
        }

        return left == 2 ? 2 * level + 1 : 2 * level;
    }

    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int d1 = findDiameter(edges1);
        int d2 = findDiameter(edges2);
        return max({d1, d2, ((d1+1)/2) + ((d2+1)/2) + 1});
    }
};