class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) {
        if (grid[0][1] > 1 && grid[1][0] > 1) return -1;
        
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        
        pq.push({0, 0, 0}); 
        vector<int> dirs = {-1, 0, 1, 0, -1};

        while (!pq.empty()) {
            int time = pq.top()[0], row = pq.top()[1], col = pq.top()[2];
            pq.pop();

            if (row == n - 1 && col == m - 1) return time;

            if (visited[row][col]) continue;
            visited[row][col] = true;

            for (int k = 0; k < 4; k++) {
                int x = row + dirs[k];
                int y = col + dirs[k + 1];

                if (x >= 0 && x < n && y >= 0 && y < m && !visited[x][y]) {
                    int nextTime = time + 1;
                    if (nextTime < grid[x][y]) {
                        nextTime = grid[x][y];
                        if ((nextTime - time) % 2 == 0) {
                            nextTime++;
                        }
                    }
                    
                    pq.push({nextTime, x, y});
                }
            }
        }

        return -1;
    }
};