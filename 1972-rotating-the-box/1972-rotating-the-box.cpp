class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int n = box.size(), m = box[0].size();
        vector<vector<char>> dp(m, vector<char>(n, '.'));

        for(int i = 0; i<n; i++) {
            int col = m - 1;
            for(int j = m - 1; j >=0; j--) {
                if(box[i][j] == '#') {
                    dp[col][n-i-1] = '#';
                    col--;
                } else if(box[i][j] == '*') {
                    dp[j][n-i-1] = '*';
                    col = j - 1;
                }
            }
        }

        return dp;
    }
};