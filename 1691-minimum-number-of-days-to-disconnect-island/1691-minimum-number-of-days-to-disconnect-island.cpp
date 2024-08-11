class Solution {
public:
    int dir[5] = {-1, 0, 1, 0, -1};
    
    void dfs(int i, int j, int n, int m, vector<vector<int>> &grid, set<pair<int,int>> &visited) {
        if (i < 0 || j < 0 || i >= n || j >= m || grid[i][j] == 0 || visited.find({i, j}) != visited.end()) return;
        visited.insert({i, j});
        for (int k = 0; k < 4; k++) {
            int x = i + dir[k];
            int y = j + dir[k+1];
            dfs(x, y, n, m, grid, visited);
        }
    }

    int countIslands(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), count = 0;
        set<pair<int,int>> visited;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1 && visited.find({i, j}) == visited.end()) {
                    dfs(i, j, n, m, grid, visited);
                    count++;
                }
            }
        }
        return count;
    }

    int minDays(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        
        int initialIslands = countIslands(grid);
        if (initialIslands != 1) return 0;  

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    grid[i][j] = 0;  
                    int newIslands = countIslands(grid);
                    grid[i][j] = 1;  

                    if (newIslands != 1) return 1;  
                }
            }
        }

        return 2;
    }
};