class Solution {
public:
    int solve(int idx, vector<int> &arr, int k, vector<int> &dp) {
        if(idx == arr.size()) return 0;
        if(dp[idx] != -1) return dp[idx];

        int len = 0, maxval = 0, maxans = 0;
        for(int i = idx; i<min(idx + k, (int)arr.size()); i++) {
            len++;
            maxval = max(maxval, arr[i]);
            int sum = len*maxval + solve(i+1, arr, k, dp);
            maxans = max(maxans, sum);
        }

        return dp[idx] = maxans;
    }

    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n, -1);
        return solve(0, arr, k, dp);
    }
};