class Solution {
    public int minTimeToVisitAllPoints(int[][] points) {
        int ans = 0, n = points.length;
        for(int i = 1; i<n; i++) {
            int[] curr = points[i];
            int[] prev = points[i-1];
            ans += Math.max(Math.abs(curr[0] - prev[0]), Math.abs(curr[1] - prev[1]));
        }
        return ans;
    }
}