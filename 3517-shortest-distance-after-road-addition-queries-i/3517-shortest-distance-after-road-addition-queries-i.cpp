class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> edges(n);
        for(int i = 0; i<n; i++) {
            edges[i].push_back(i+1);
        }

        auto shortestPath = [&]() {
            queue<pair<int,int>> pq;
            pq.push({0, 0});
            unordered_set<int> visited;
            visited.insert(0);

            while(!pq.empty()) {
                auto [curr, len] = pq.front();
                pq.pop();

                if(curr == n - 1) return len;

                for(int node : edges[curr]) {
                    if(visited.find(node) == visited.end()) {
                        pq.push({node, len+1});
                        visited.insert(node);
                    }
                }
            }

            return -1;
        };

        vector<int> ans;
        for(auto &q : queries) {
            edges[q[0]].push_back(q[1]);
            ans.push_back(shortestPath());
        }

        return ans;
    }
};