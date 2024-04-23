class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 0) return {};
        else if(n == 1) return {0};
        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0);

        for(auto it : edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
            indegree[it[0]]++;
            indegree[it[1]]++;
        }

        vector<int> ans;
        queue<int> pq;
        for(int i = 0; i<n; i++) {
            if(indegree[i] == 1) pq.push(i);
        }

        while(!pq.empty()) {
            ans.clear();
            int len = pq.size();
            for(int i = 0; i<len; i++) {
                int curr = pq.front();
                pq.pop();
                ans.push_back(curr);

                for(auto it : adj[curr]) {
                    indegree[it]--;
                    if(indegree[it] == 1) {
                        pq.push(it);
                    }
                }
            }
        }

        return ans;
    }
};