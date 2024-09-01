class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        int len = original.size();
        vector<vector<int>> ans;
        if (n * m != len) return ans;

        ans = vector<vector<int>>(m, vector<int>(n));
        int idx = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                ans[i][j] = original[idx];
                idx++;
            }
        }

        return ans;
    }
};