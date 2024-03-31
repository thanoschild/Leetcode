class Solution {
    public long countSubarrays(int[] nums, int minK, int maxK) {
        int n = nums.length, maxIdx = -1, minIdx = -1, badIdx = 0;
        long ans = 0;

        for(int i = 0; i<n; i++) {
            if(nums[i] < minK || nums[i] > maxK) badIdx = i + 1;
            if(nums[i] == minK) minIdx = i;
            if(nums[i] == maxK) maxIdx = i;
            ans += Math.max(0, Math.min(minIdx, maxIdx) - badIdx + 1);
        }

        return ans;
    }
}