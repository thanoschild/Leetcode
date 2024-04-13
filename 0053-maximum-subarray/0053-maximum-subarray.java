class Solution {
    public int maxSubArray(int[] nums) {
        int maxSum = Integer.MIN_VALUE, currSum = 0;
        for(int num : nums) {
            currSum = Math.max(currSum, 0) + num;
            maxSum = Math.max(maxSum, currSum);
        }

        return maxSum;
    }
}