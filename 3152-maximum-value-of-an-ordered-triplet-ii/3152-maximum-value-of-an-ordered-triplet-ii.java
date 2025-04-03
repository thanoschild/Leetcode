class Solution {
    public long maximumTripletValue(int[] nums) {
        long ans = 0, maxDiff = -1, maxVal = -1;

        for(int it : nums) {
            ans = Math.max(ans, maxDiff * (1L * it));
            maxVal = Math.max(maxVal, 1L * it);
            maxDiff = Math.max(maxDiff, maxVal - (1L * it));
        }

        return ans;
    }
}