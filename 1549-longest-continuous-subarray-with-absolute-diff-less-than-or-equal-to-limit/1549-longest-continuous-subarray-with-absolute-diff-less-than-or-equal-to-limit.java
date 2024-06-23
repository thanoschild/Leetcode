class Solution {
    public int longestSubarray(int[] nums, int limit) {
        int ans = 0, j = 0, i = 0, n = nums.length;
        TreeMap<Integer, Integer> mp = new TreeMap<>();
        for(i = 0; i<n; i++) {
            mp.put(nums[i], mp.getOrDefault(nums[i], 0) + 1);
            if(mp.lastEntry().getKey() - mp.firstEntry().getKey() > limit) {
                mp.put(nums[j], mp.get(nums[j]) - 1);
                if(mp.get(nums[j]) == 0) mp.remove(nums[j]);
                j++;
            }
        }

        return i - j;
    }
}