class Solution {
public:
    int dp[101][201];
    int solve(int i, int m, vector<int> &arr) {
        if(i >= arr.size()) return 0;
        if(dp[i][m] != -1) return dp[i][m];
        int ans = INT_MIN, total = 0;
        for(int j = 0; j<2*m && i + j < arr.size(); j++) {
            total += arr[i+j];
            ans = max(ans, total - solve(i+j+1, max(m, j+1), arr));
        }
        return dp[i][m] = ans;
    }

    int stoneGameII(vector<int>& piles) {
       memset(dp, -1, sizeof(dp));
       int sum = 0;
       for(auto it : piles) sum += it;
       int diff = solve(0, 1, piles);
       return (sum + diff)/2; 
    }
};