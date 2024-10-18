class Solution {
    int ans;
    private void maxSubset(int[] nums, int i, int currOr, int maxOr) {
        if(i == nums.length) {
            if(currOr == maxOr) ans++;
            return;
        }

        maxSubset(nums, i+1, currOr | nums[i], maxOr);
        maxSubset(nums, i+1, currOr, maxOr);
    }

    public int countMaxOrSubsets(int[] nums) {
        int maxOr = 0;
        ans = 0;
        for(int n : nums) maxOr |= n;
        maxSubset(nums, 0, 0, maxOr);
        return ans;
    }
}