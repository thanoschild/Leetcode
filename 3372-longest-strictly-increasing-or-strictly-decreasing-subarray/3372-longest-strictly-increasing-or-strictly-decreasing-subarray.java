class Solution {
    public int longestMonotonicSubarray(int[] nums) {
        int n = nums.length, count = 1, ans = 1;
        for(int i = 1; i<n; i++) {
            if(nums[i-1] < nums[i]) count++;
            else count = 1;
            ans = Math.max(count, ans);
        }

        count = 1;
        for(int i = n - 2; i>=0; i--) {
           if(nums[i] > nums[i+1]) count++;
           else count = 1;
           ans = Math.max(count, ans);
        }

        return ans;
    }
}