class Solution {
    int idx;
    private void addPath(int r, int c, int rows, int cols, int[][] ans) {
        if(r >= 0 && r < rows && c >= 0 && c < cols) {
            ans[idx][0] = r;
            ans[idx][1] = c;
            idx++;
        }
    }

    public int[][] spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        int c = cStart, r = rStart, len = 1;
        idx = 0;
        int[][] ans = new int[rows*cols][2];

        while(idx < rows * cols) {
            for(int k = 0; k<len; k++) addPath(r, c++, rows, cols, ans);
            for(int k = 0; k<len; k++) addPath(r++, c, rows, cols, ans);
            len++;
            for(int k = 0; k<len; k++) addPath(r, c--, rows, cols, ans);
            for(int k = 0; k<len; k++) addPath(r--, c, rows, cols, ans);
            len++;
        }

        return ans;
    }
}