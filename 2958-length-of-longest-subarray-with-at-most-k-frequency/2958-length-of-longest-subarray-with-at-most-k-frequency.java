class Solution {
    public int maxSubarrayLength(int[] nums, int k) {
        int n = nums.length, ans = 0;
        HashMap<Integer, Integer> mp = new HashMap<>();

        for(int i = 0, j = 0; j<n; j++) {
            mp.put(nums[j], mp.getOrDefault(nums[j], 0) + 1);
            if(mp.get(nums[j]) > k) {
                while(nums[i] != nums[j]) {
                    mp.put(nums[i], mp.get(nums[i]) - 1);
                    i++;
                }
                mp.put(nums[i], mp.get(nums[i]) - 1);
                i++;
            }
            ans = Math.max(ans, j - i + 1);
        }

        return ans;
    }
}