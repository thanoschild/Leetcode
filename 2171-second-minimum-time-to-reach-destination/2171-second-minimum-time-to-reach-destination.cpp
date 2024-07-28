class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        vector<vector<int>> adj(n+1);
        for(auto it : edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        queue<vector<int>> pq;
        pq.push({1, 0});
        vector<int> visitTime(n+1, 0);
        vector<int> visit(n+1, 0);
        int firstVisit = INT_MAX;

        while(!pq.empty()) {
            auto it = pq.front();
            pq.pop();
            int node = it[0], t = it[1];

            for(int x : adj[node]) {
                int t2 = t;
                bool isRed = (t2 / change) % 2;
                if(isRed) t2 += change - (t2 % change);
                t2 += time;

                if(x == n && firstVisit == INT_MAX) firstVisit = t2;
                if(x == n && t2 > firstVisit) return t2;
                if(visitTime[x] != t2 && visit[x] <= 1) {
                    visitTime[x] = t2;
                    visit[x]++;
                    pq.push({x, t2});
                }
            }
        }

        return -1;
    }
};