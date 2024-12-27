class Solution {
    public int maxScoreSightseeingPair(int[] values) {
        int ans = Integer.MIN_VALUE, curr = values[0];
        for(int i = 1; i<values.length; i++) {
            ans = Math.max(ans, curr + values[i] - i);
            curr = Math.max(curr, values[i] + i);
        }

        return ans;
    }
}