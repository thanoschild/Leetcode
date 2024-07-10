class Solution {
    public double averageWaitingTime(int[][] customers) {
        double ans = 0, curr = 0;
        for(int[] c : customers) {
            curr = Math.max(curr, 1.0 * c[0]) + c[1];
            ans += curr - c[0];
        }

        return 1.0 * ans / customers.length;
    }
}