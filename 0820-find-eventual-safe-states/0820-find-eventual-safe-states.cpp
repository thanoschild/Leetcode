class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<bool> seen(n, false), visited(n, false), cycle(n, false);

        function<bool(int)> dfs = [&](int i) {
            seen[i] = true;
            if(!visited[i]) {
                visited[i] = true;
                for(int it : graph[i]) {
                    if(!visited[it] && dfs(it)) {
                        cycle[i] = true;
                        return cycle[i];
                    }
                    if(seen[it]) {
                        cycle[i] = true;
                        return cycle[i];
                    }
                }
            }
            seen[i] = false;
            return seen[i];
        };

        for(int i = 0; i<n; i++) {
            if(!visited[i]) dfs(i);
        }

        vector<int> ans;
        for(int i = 0; i<n; i++) {
            if(!cycle[i]) ans.push_back(i);
        }

        return ans; 
    }
};