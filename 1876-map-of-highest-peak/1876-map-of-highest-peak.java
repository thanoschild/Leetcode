class Solution {
    public int[][] highestPeak(int[][] mat) {
        int n = mat.length, m = mat[0].length;
        int[][] ans = new int[n][m];
        Queue<int[]> pq = new LinkedList<>();
        int[] dirs = {-1, 0, 1, 0, -1};

        for(int i = 0; i<n; i++) {
            for(int j = 0; j<m; j++) {
                ans[i][j] = -1;
                if(mat[i][j] == 1) {
                    ans[i][j] = 0;
                    pq.add(new int[] {i, j});
                }
            }
        }

        while(!pq.isEmpty()) {
            int[] cell = pq.poll();
            int x = cell[0], y = cell[1];
            for(int k = 0; k<4; k++) {
                int dx = x + dirs[k];
                int dy = y + dirs[k+1];
                if(dx >= 0 && dx < n && dy >= 0 && dy < m && ans[dx][dy] == -1) {
                    ans[dx][dy] = 1 + ans[x][y];
                    pq.add(new int[] {dx, dy});
                }
            }
        }

        return ans;
    }
}