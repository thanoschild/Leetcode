class Solution {
    public int[] missingRolls(int[] rolls, int mean, int n) {
        int sum = 0;
        for (int roll : rolls) {
            sum += roll;
        }

        int m = rolls.length;
        int missingSum = mean * (n + m) - sum;
        if (missingSum < n || missingSum > n * 6) return new int[0];

        int val = missingSum / n;
        int rem = missingSum % n;
        int[] ans = new int[n];
        Arrays.fill(ans, val);

        for (int i = 0; i < rem; i++) {
            ans[i]++;
        }

        return ans;
    }
}