class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& mat, int target) {
        int n = mat.size(), m = mat[0].size();
        for(int i = 0; i<n; i++) {
            for(int j = 1; j<m; j++) {
                mat[i][j] += mat[i][j-1];
            }
        }

        int ans = 0;
        for(int i = 0; i<m; i++) {
            for(int col = i; col<m; col++) {
                unordered_map<int, int> mp;
                mp[0]++;
                int sum = 0;
                for(int row = 0; row<n; row++) {
                    sum += mat[row][col] - (i > 0 ? mat[row][i-1] : 0);
                    ans += mp[sum - target];
                    mp[sum]++;
                }
            }
        }

        return ans;
    }
};