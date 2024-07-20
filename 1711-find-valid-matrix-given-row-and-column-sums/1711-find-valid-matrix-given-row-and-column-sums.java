class Solution {
    public int[][] restoreMatrix(int[] row, int[] col) {
        int n = row.length, m = col.length;
        int[][] ans = new int[n][m];

        for(int i = 0; i<n; i++) {
            for(int j = 0; j<m; j++) {
                ans[i][j] = Math.min(row[i], col[j]);
                row[i] -= ans[i][j];
                col[j] -= ans[i][j];
            }
        }

        return ans;
    }
}