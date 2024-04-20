class Solution {
    int [] dir = {-1, 0, 1, 0, -1};
    private void dfs(int[][] grid, int i, int j, int n, int m, int[] curr) {
        if(i < 0 || i >= n || j < 0 || j >= m || grid[i][j] == 0) return;

        grid[i][j] = 0;
        curr[2] = Math.max(i, curr[2]);
        curr[3] = Math.max(j, curr[3]);
        for(int k = 0; k<4; k++) {
            int x = dir[k] + i;
            int y = dir[k + 1] + j;
            dfs(grid, x, y, n, m, curr);
        }
    }

    public int[][] findFarmland(int[][] grid) {
        List<int[]> resultList = new ArrayList<>();
        int n = grid.length;
        int m = grid[0].length;

        for(int i = 0; i<n; i++) {
            for(int j = 0; j<m; j++) {
                if(grid[i][j] == 1) {
                    int[] curr = new int[4];
                    curr[0] = curr[2] = i;
                    curr[1] = curr[3] = j;
                    dfs(grid, i, j, n, m, curr);
                    resultList.add(curr);
                }
            }
        }

        int[][] ans = new int[resultList.size()][4];
        for(int i = 0; i<resultList.size(); i++) {
            ans[i] = resultList.get(i);
        }

        return ans;
    }
}