class Solution {
    public boolean isPossible(int curr_day, int [] days) {
        for(int i = 0; i<days.length; i++){
            if(curr_day == days[i]) return true;
        }
        return false;
    }

    public int solve(int curr_day, int[] days, int[] costs, int[] dp) {
        int n = days.length;
        if(curr_day > days[n-1]) return 0;
        if(dp[curr_day] != -1) return dp[curr_day];

        int ans = Integer.MAX_VALUE;
        if(isPossible(curr_day, days)){
            ans = solve(curr_day + 1, days, costs, dp) + costs[0];
            ans = Math.min(ans, solve(curr_day + 7, days, costs, dp) + costs[1]);
            ans = Math.min(ans, solve(curr_day + 30, days, costs, dp) + costs[2]);
        }
        else{
            ans = solve(curr_day + 1, days, costs, dp);
        }

        return dp[curr_day] = ans;
    }

    public int mincostTickets(int[] days, int[] costs) {
        int n = days.length;
        int[] dp = new int[days[n-1] + 1];
        Arrays.fill(dp, -1);
        return solve(days[0], days, costs, dp);
    }
}