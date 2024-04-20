class Solution {
public:
    int dir[5] = {-1, 0, 1, 0, -1};
    void dfs(vector<vector<int>> &land, int i, int j, int n, int m, vector<int> &curr) {
        if(i < 0 || i >= n || j < 0 || j >= m || land[i][j] == 0) return;

        land[i][j] = 0;
        curr[2] = max(curr[2], i);
        curr[3] = max(curr[3], j);

        for(int k = 0; k<4; k++) {
            int x = dir[k] + i;
            int y = dir[k+1] + j;
            dfs(land, x, y, n, m, curr);
        }
    }

    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        vector<vector<int>> ans;
        int n = land.size();
        int m = land[0].size();

        for(int i = 0; i<n; i++) {
            for(int j = 0; j<m; j++) {
                if(land[i][j] == 1) {
                    vector<int> curr(4); 
                    curr[0] = i, curr[1] = j;
                    curr[2] = i, curr[3] = j;
                    dfs(land, i, j, n, m, curr);
                    ans.push_back(curr);
                }
            }
        }

        return ans;
    }
};