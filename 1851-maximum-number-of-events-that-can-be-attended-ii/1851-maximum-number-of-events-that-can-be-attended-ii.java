class Solution {
    public int maxValue(int[][] events, int k) {
        int n = events.length;
        int[][] dp = new int[n+1][k+1];
        for(int[] row : dp) Arrays.fill(row, -1);
        Arrays.sort(events, Comparator.comparingInt(a -> a[0]));
        return solve(events, 0, k, dp);
    }

    private int solve(int[][] events, int pos, int k, int[][] dp) {
        if(pos >= events.length || k == 0) return 0;
        if(dp[pos][k] != -1) return dp[pos][k];

        int notTake = solve(events, pos + 1, k, dp);
        int next = findNextEvent(events, events[pos][1] + 1);
        int take = solve(events, next, k - 1, dp) + events[pos][2];
        dp[pos][k] = Math.max(notTake, take);
        return dp[pos][k];
    }

    private int findNextEvent(int[][] events, int value) {
        int left = 0, right = events.length-1;
        while(left <= right) {
            int mid = (right + left) / 2;
            if(events[mid][0] < value) left = mid + 1;
            else right = mid - 1;
        }

        return left;
    }
}