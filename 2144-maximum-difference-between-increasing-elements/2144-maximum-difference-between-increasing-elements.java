class Solution {
    public int maximumDifference(int[] nums) {
        int ans = -1, minVal = nums[0];
        for(int it : nums) {
            ans = Math.max(ans, it - minVal);
            minVal = Math.min(minVal, it);
        }

        return ans == 0 ? -1 : ans;
    }
}