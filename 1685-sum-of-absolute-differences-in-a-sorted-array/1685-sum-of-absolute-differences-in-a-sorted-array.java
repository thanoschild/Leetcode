class Solution {
    public int[] getSumAbsoluteDifferences(int[] nums) {
        int right = Arrays.stream(nums).sum();
        int left = 0, n = nums.length;
        int[] ans = new int[n];
        
        for(int i = 0; i<n; i++) {
            int val = nums[i];
            right -= val;
            ans[i] = val*i - left + right - val*(n - i - 1);
            left += val;
        }
        
        return ans;
    }
}