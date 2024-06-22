class Solution {
    private int atMostK(int[] nums, int k) {
        int ans = 0, count = 0;
        for(int i = 0, j = 0; i<nums.length; i++) {
            count += nums[i] % 2;
            while(count > k) {
                count -= nums[j++] % 2;
            }
            ans += (i - j);
        }

        return ans;
    }
    
    public int numberOfSubarrays(int[] nums, int k) {
        return atMostK(nums, k) - atMostK(nums, k - 1);
    }
}