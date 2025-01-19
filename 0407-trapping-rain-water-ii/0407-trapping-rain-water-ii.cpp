class Solution {
public:
    int trapRainWater(vector<vector<int>>& height) {
        int n = height.size();
        int m = height[0].size();
        int dirs[5] = {-1, 0, 1, 0, -1};
        int water = 0;
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

        for(int i = 0; i<n; i++) {
            if(!visited[i][0]) {
                visited[i][0] = true;
                pq.push({height[i][0], i, 0});
            }
            if(!visited[i][m-1]) {
                visited[i][m-1] = true;
                pq.push({height[i][m-1], i, m-1});
            }
        }

        for(int j = 0; j<m; j++) {
            if(!visited[0][j]) {
               visited[0][j] = true;
               pq.push({height[0][j], 0, j});
            }
            if(!visited[n-1][j]) {
                visited[n-1][j] = true;
                pq.push({height[n-1][j], n-1, j});
            }
        }

        function<void()> bfs = [&]() {
            while(!pq.empty()) {
                auto t = pq.top();
                pq.pop();
                int h = t[0], x = t[1], y = t[2];

                for(int k = 0; k<4; k++) {
                    int dx = x + dirs[k];
                    int dy = y + dirs[k+1];
                    if(dx >= 0 && dx < n && dy >= 0 && dy < m && !visited[dx][dy]) {
                       visited[dx][dy] = true;
                       if(height[dx][dy] >= h) {
                          pq.push({height[dx][dy], dx, dy});
                       } else {
                          water += h - height[dx][dy];
                          height[dx][dy] = h;
                          pq.push({h, dx, dy});
                       }
                    }
                }
            }
        };

        bfs();
        return water;
    }
};