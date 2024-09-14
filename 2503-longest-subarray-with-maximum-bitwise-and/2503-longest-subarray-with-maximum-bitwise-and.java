class Solution {
    public int longestSubarray(int[] nums) {
        int mx = -1, count = 0, ans = 0;
        for(int it : nums) mx = Math.max(mx, it);

        for(int it : nums) {
            if(mx == it) count++;
            else count = 0;
            ans = Math.max(ans, count);
        }

        return ans;
    }
}