class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        for(int i = 1; i<n; i++) {
            for(int j = 0; j<m; j++) {
                if(mat[i][j] == 1) mat[i][j] += mat[i-1][j];
            }
        }
        
        int ans = 0;
        for(auto v : mat) {
            sort(v.begin(), v.end());
            for(int j = m - 1, k = 1; j >= 0 && v[j] > 0; j--, k++) {
                ans = max(ans, v[j]*k);
            }
        }
        
        return ans;
    }
};