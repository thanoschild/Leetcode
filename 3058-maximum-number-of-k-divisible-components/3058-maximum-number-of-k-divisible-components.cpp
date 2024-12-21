class Solution {
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        unordered_map<int, vector<int>> adj;
        for(auto it : edges) {
           adj[it[0]].push_back(it[1]);
           adj[it[1]].push_back(it[0]);
        }

        int ans = 0;
        function<long long(int, int)> dfs = [&](int curr, int parent) {
            long long total = values[curr];
            for(auto it : adj[curr]) {
                if(it != parent) {
                   total += dfs(it, curr);
                }
            }

            if(total % k == 0) {
                ans += 1;
            }

            return total;
        };

        dfs(0, -1);
        return ans;
    }
};