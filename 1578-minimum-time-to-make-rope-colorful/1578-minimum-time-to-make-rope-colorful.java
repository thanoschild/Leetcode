class Solution {
    public int minCost(String colors, int[] time) {
        int ans = 0, max_time = 0, sum = 0;
        for(int i = 0; i<colors.length(); i++) {
            if(i > 0 && colors.charAt(i) != colors.charAt(i-1)) {
                ans += sum - max_time;
                sum = 0; max_time = 0;
            }
            sum += time[i];
            max_time = Math.max(max_time, time[i]);
        }
        ans += sum - max_time;

        return ans;
    }
}