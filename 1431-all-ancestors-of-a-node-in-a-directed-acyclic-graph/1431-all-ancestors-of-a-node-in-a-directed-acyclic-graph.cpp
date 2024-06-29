class Solution {
public:
    void dfs(int i, vector<int> &curr, vector<bool> &visited, vector<vector<int>> &adj) {
        visited[i] = true;
        for(auto it : adj[i]) {
            if(!visited[it]) {
                curr.push_back(it);
                dfs(it, curr, visited, adj);
            }
        }
    }
    
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto it : edges) {
            adj[it[1]].push_back(it[0]);
        }

        vector<bool> visited(n, false);
        vector<vector<int>> ans;
        for(int i = 0; i<n; i++) {
            vector<int> curr;
            dfs(i, curr, visited, adj);
            sort(curr.begin(), curr.end());
            ans.push_back(curr);
            fill(visited.begin(), visited.end(), false);
        }

        return ans;
    }
};