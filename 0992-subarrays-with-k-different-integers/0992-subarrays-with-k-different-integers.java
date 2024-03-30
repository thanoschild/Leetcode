class Solution {
    public int findKmostSubarrays(int[] nums, int n, int k) {
        int count = 0;
        HashMap<Integer, Integer> mp = new HashMap<>();

        for(int i = 0, j = 0; j<n; j++) {
            mp.put(nums[j], mp.getOrDefault(nums[j], 0) + 1);
            while(mp.size() > k) {
                mp.put(nums[i], mp.get(nums[i]) - 1);
                if(mp.get(nums[i]) == 0) {
                    mp.remove(nums[i]);
                }
                i++;
            }
            count += (j - i + 1);
        }

        return count;
    }

    public int subarraysWithKDistinct(int[] nums, int k) {
        int n = nums.length;
        int ans1 = findKmostSubarrays(nums, n, k);
        int ans2 = findKmostSubarrays(nums, n, k - 1);
        return ans1 - ans2;
    }
}