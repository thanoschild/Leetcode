class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> visited(n, vector<int>(m, -1));
        queue<pair<int,int>> pq;
        int dirs[5] = {-1, 0, 1, 0, -1};

        for(int i = 0; i<n; i++) {
            for(int j = 0; j<m; j++) {
                if(mat[i][j] == 1) {
                    visited[i][j] = 0;
                    pq.push({i, j});
                }
            }
        }

        while(!pq.empty()) {
            auto[x, y] = pq.front();
            pq.pop();
            for(int k = 0; k<4; k++) {
                int dx = x + dirs[k];
                int dy = y + dirs[k+1];
                if(dx >= 0 && dx < n && dy >= 0 && dy < m && visited[dx][dy] == -1) {
                   visited[dx][dy] = 1 + visited[x][y];
                   pq.push({dx, dy});
                }
            }
        }

        return visited;
    }
};