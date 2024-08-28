class Solution {
public:
    int v[5] = {-1, 0, 1, 0, -1};
    void dfs(vector<vector<int>> &grid, int i, int j)
    {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || !grid[i][j])
            return;
        grid[i][j] = 0;
        for (int k = 0; k < 4; k++)
        {
            int x = i + v[k];
            int y = j + v[k + 1];
            dfs(grid, x, y);
        }
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
       int n = grid2.size();
       int m = grid2[0].size();
       int count = 0;
       for(int i = 0; i<n; i++){
           for(int j = 0; j<m; j++){
               if(grid1[i][j] == 0){
                   dfs(grid2, i, j);
               }
           }
       }
       
       for (int i = 0; i < n; i++) {
           for (int j = 0; j < m; j++) {
               if (grid2[i][j]) {
                   dfs(grid2, i, j);
                   count++;
               }
           }
       }

       return count;
    }
};