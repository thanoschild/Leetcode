class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto it : edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        vector<bool> seen(n, false);
        function<void(int, int&, int&)> dfs = [&](int node, int &nodeCount, int &edgeCount) {
           if(seen[node]) return;
           seen[node] = true;
           nodeCount++;
           edgeCount += adj[node].size();
           for(auto it : adj[node]) dfs(it, nodeCount, edgeCount);
        };

        int ans = 0;
        for(int i = 0; i<n; i++) {
            if(!seen[i]) {
                int nodeCount = 0, edgeCount = 0;
                dfs(i, nodeCount, edgeCount);
                if((nodeCount * (nodeCount - 1)) == edgeCount) ans++;
            }
        }

        return ans;
    }
};