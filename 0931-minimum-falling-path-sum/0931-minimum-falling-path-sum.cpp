class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& mat) {
        int m = mat.size();
        auto M = [&](int i, int j) {
            return j >= 0 && j < m ? mat[i][j] : INT_MAX;
        };

        for(int i = 1; i<m; i++) {
            for(int j = 0; j<m; j++) {
                mat[i][j] += min(mat[i-1][j], min(M(i-1, j-1), M(i-1, j+1)));
            }
        }

        return *min_element(mat.back().begin(), mat.back().end());
    }
};