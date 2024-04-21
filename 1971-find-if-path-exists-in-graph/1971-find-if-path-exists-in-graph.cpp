class Solution {
public:
    void dfs(vector<vector<int>> & edges, vector<bool> &seen, int idx, int dest) {
        if(seen[idx]) return;
        seen[idx] = true;

        if(seen[dest]) return;
        for(auto it : edges[idx]) {
            dfs(edges, seen, it, dest);
        }
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<bool> seen(n, false);
        vector<vector<int>> adj(n);
        for(auto it : edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        dfs(adj, seen, source, destination);
        if(seen[destination]) return true;
        return false;
    }
};