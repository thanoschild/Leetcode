class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> distance(n, vector<int>(m, INT_MAX));
        deque<pair<int,int>> pq;

        distance[0][0] = 0;
        pq.push_front({0, 0});
        int dirs[5] = {-1, 0, 1, 0, -1};
        while(!pq.empty()) {
            auto [x, y] = pq.front();
            pq.pop_front();
            
            for(int k = 0; k<4; k++) {
                int dx = x + dirs[k];
                int dy = y + dirs[k+1];

                if(dx >= 0 && dx < n && dy >= 0 && dy < m) {
                    int dist = distance[x][y] + grid[dx][dy];
                    if(dist < distance[dx][dy]) {
                        distance[dx][dy] = dist;
                        if(grid[dx][dy] == 0) {
                            pq.push_front({dx, dy});
                        } else {
                            pq.push_back({dx, dy});
                        }
                    }
                }
            }
        }

        return distance[n-1][m-1];
    }
};