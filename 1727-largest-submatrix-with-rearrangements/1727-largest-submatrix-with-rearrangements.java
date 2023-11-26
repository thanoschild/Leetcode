class Solution {
    public int largestSubmatrix(int[][] mat) {
        int n = mat.length, m = mat[0].length;
        for(int i = 1; i<n; i++) {
            for(int j = 0; j<m; j++) {
                if(mat[i][j] == 1) mat[i][j] += mat[i-1][j];
            }
        }
        
        int ans = 0;
        for(var v : mat) {
            Arrays.sort(v);
            for(int j = m - 1, k = 1; j >= 0 && v[j] > 0; j--, k++) {
                ans = Math.max(ans, v[j]*k);
            }
        }
        
        return ans;
    }
}