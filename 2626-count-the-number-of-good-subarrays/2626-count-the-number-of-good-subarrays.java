class Solution {
    public long countGood(int[] nums, int k) {
        int n = nums.length;
        long ans = 0;
        HashMap<Integer, Integer> freq = new HashMap<>();

        for(int i = 0, j = 0; i<n; i++) {
            k -= freq.getOrDefault(nums[i], 0);
            freq.put(nums[i], freq.getOrDefault(nums[i], 0) + 1);
            while(k <= 0) {
                freq.put(nums[j], freq.getOrDefault(nums[j], 0) - 1);
                k += freq.getOrDefault(nums[j], 0);
                j++;
            }

            ans += j;
        }

        return ans;
    }
}