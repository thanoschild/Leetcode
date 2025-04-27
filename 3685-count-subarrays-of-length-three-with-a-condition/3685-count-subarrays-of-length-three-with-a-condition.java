class Solution {
    public int countSubarrays(int[] nums) {
        int ans = 0, n = nums.length;
        for(int i = 0; i<n-2; i++) {
            int a = (nums[i] + nums[i + 2]) * 2;
            int b = nums[i + 1];
            if(a == b) ans++;
        }

        return ans;
    }
}