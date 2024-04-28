class Solution {
public:
    vector<int> count, ans;
    void dfs(vector<unordered_set<int>> &adj, int root, int parent) {
        for(int node : adj[root]) {
            if(node == parent) continue;
            dfs(adj, node, root);
            count[root] += count[node];
            ans[root] += ans[node] + count[node];
        }
    }

    void dfs2(vector<unordered_set<int>> &adj, int root, int parent) {
        for(int node : adj[root]) {
            if(node == parent) continue;
            ans[node] = ans[root] - count[node] + count.size() - count[node];
            dfs2(adj, node, root);
        }
    }

    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        count.resize(n, 1);
        ans.resize(n, 0);

        vector<unordered_set<int>> adj(n);
        for(auto edge : edges) {
            adj[edge[0]].insert(edge[1]);
            adj[edge[1]].insert(edge[0]);
        }

        dfs(adj, 0, -1);
        dfs2(adj, 0, -1);
        return ans;
    }
};