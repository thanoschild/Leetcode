class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<int> seenRow(n, 0);
        vector<int> seenCol(m, 0);

        for(int i = 0; i<n; i++) {
            for(int j = 0; j<m; j++) {
                if(grid[i][j] == 1) {
                    seenRow[i]++;
                    seenCol[j]++;
                }
            }
        }

        int ans = 0;
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<m; j++) {
                if(grid[i][j] == 1 && (seenRow[i] > 1 || seenCol[j] > 1)) ans++;
            }
        }

        return ans;
    }
};