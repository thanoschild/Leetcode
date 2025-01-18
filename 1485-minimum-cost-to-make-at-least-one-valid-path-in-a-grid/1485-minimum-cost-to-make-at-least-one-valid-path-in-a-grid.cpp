class Solution {
public:
    int dirX[4] = {0, 0, 1, -1};
    int dirY[4] = {1, -1, 0, 0};
    int minCost(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        deque<pair<int,int>> pq;
        pq.push_front({0, 0});
        dist[0][0] = 0;

        while(!pq.empty()) {
            auto [x, y] = pq.front();
            pq.pop_front();
            for(int i = 0; i<4; i++) {
                int dx = x + dirX[i], dy = y + dirY[i];
                if(dx >= 0 && dx < n && dy >= 0 && dy < m) {
                    int cost = (i + 1 == grid[x][y]) ? 0 : 1;
                    if(dist[x][y] + cost < dist[dx][dy]) {
                        dist[dx][dy] = dist[x][y] + cost;
                        if(cost == 0) pq.push_front({dx, dy});
                        else pq.push_back({dx, dy});
                    }
                }
            }
        }

        return dist[n - 1][m - 1];
    }
};