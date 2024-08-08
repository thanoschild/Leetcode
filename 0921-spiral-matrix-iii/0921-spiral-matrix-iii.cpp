class Solution {
public:
    int idx;
    vector<vector<int>> ans;

    void addPath(int r, int c, int rows, int cols) {
        if(r >= 0 && r < rows && c >= 0 && c < cols) {
            ans[idx][0] = r;
            ans[idx][1] = c;
            idx++;
        }
    }

    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        int r = rStart, c = cStart, len = 1;
        idx = 0;
        ans = vector<vector<int>> (rows * cols, vector<int>(2));
        while(idx < (rows * cols)) {
            for(int k = 0; k<len; k++) addPath(r, c++, rows, cols);
            for(int k = 0; k<len; k++) addPath(r++, c, rows, cols);
            len++;
            for(int k = 0; k<len; k++) addPath(r, c--, rows, cols);
            for(int k = 0; k<len; k++) addPath(r--, c, rows, cols);
            len++;
        }

        return ans;
    }
};