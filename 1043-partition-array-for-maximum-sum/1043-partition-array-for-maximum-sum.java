class Solution {
    public int solve(int idx, int[] arr, int k, Integer[] dp) {
        if(idx == arr.length) return 0;
        if(dp[idx] != null) return dp[idx];

        int len = 0, maxval = 0, maxans = 0;
        for(int i = idx; i<Math.min(idx + k, arr.length); i++) {
            len++;
            maxval = Math.max(maxval, arr[i]);
            int sum = len*maxval + solve(i+1, arr, k, dp);
            maxans = Math.max(maxans, sum);
        }
 
        return dp[idx] = maxans;
    }
    
    public int maxSumAfterPartitioning(int[] arr, int k) {
        int n = arr.length;
        Integer[] dp = new Integer[n];
        return solve(0, arr, k, dp);
    }
}