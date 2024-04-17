class Solution {
public:
    void rotate(vector<vector<int>>& mat) {
        int n = mat.size();
        for(int i = 0; i<n; i++) {
            for(int j = i; j<n; j++) {
                int temp = mat[i][j];
                mat[i][j] = mat[j][i];
                mat[j][i] = temp;
            }
        }

        for(int i = 0; i<n; i++) {
            reverse(mat[i].begin(), mat[i].end());
        }
    }
};