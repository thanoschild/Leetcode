class Solution {
public:
    int dir[5] = {-1, 0, 1, 0, -1};

    struct mycompare {
        bool operator()(const vector<int> &v1, const vector<int> &v2) {
            return v1[0] < v2[0];
        }
    };

    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<pair<int,int>> pq;
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<n; j++) {
                if(grid[i][j]) pq.push({i, j});
            }
        }

        while(!pq.empty()) {
            auto[i, j] = pq.front();
            pq.pop();
            for(int k = 0; k<4; k++) {
                int x = dir[k] + i;
                int y = dir[k+1] + j;
                if(min(x, y) >= 0 && max(x, y) < n && grid[x][y] == 0) {
                    grid[x][y] = grid[i][j] + 1;
                    pq.push({x,y});
                }
            }
        }

        priority_queue<vector<int>, vector<vector<int>>, mycompare> dist;
        dist.push({grid[0][0], 0, 0});
        grid[0][0] = -1;

        while(dist.top()[1] < n - 1 || dist.top()[2] < n - 1) {
            vector<int> t = dist.top();
            dist.pop();
            int d = t[0], i = t[1], j = t[2];
            for(int k = 0; k<4; k++) {
                int x = i + dir[k];
                int y = j + dir[k + 1];
                if(min(x, y) >= 0 && max(x, y) < n && grid[x][y] != -1) {
                    dist.push({min(d, grid[x][y]), x, y});
                    grid[x][y] = -1;
                }
            }
        }

        return dist.top()[0]-1;
    }
};