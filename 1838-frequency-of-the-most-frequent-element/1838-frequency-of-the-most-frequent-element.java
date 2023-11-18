class Solution {
    public int maxFrequency(int[] nums, int k) {
        int freq = 0, left = 0;
        long sum = 0;
        Arrays.sort(nums);
        for(int right = 0; right<nums.length; right++) {
            sum += nums[right];
            while((long)sum + k < (long) nums[right] * (right - left + 1)) {
               sum -= nums[left]; left++;
            }
            freq = Math.max(freq, (right - left + 1));
        }
        return freq;
    }
}