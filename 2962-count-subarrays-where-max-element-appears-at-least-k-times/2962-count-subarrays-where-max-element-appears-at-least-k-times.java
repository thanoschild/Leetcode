class Solution {
    public long countSubarrays(int[] nums, int k) {
        int n = nums.length, count = 0;
        int maxEle = Arrays.stream(nums).max().getAsInt();
        long ans = 0;
        
        for(int i = 0, j = 0; j<n; j++) {
            count += nums[j] == maxEle ? 1 : 0;
            while(count >= k) {
                count -= nums[i] == maxEle ? 1 : 0;
                i++;
            }
            ans += i;
        }

        return ans;
    }
}