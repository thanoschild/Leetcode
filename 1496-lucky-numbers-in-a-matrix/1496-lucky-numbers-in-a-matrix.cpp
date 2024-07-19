class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<int> mi(n, INT_MAX);
        vector<int> mx(m, 0);

        for(int i = 0; i<n; i++) {
            for(int j = 0; j<m; j++) {
                mi[i] = min(mi[i], mat[i][j]);
                mx[j] = max(mx[j], mat[i][j]);
            }
        }

        vector<int> ans;
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<m; j++) {
                if(mi[i] == mx[j]) {
                    ans.push_back(mi[i]);
                    break;
                }
            }
        }

        return ans;
    }
};