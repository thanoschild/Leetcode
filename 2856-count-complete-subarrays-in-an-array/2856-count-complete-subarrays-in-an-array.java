class Solution {
    public int countCompleteSubarrays(int[] nums) {
        int dist = (int)Arrays.stream(nums).distinct().count();
        int n = nums.length, ans = 0;
        Map<Integer, Integer> freq = new HashMap<>();

        for(int i = 0, j = 0; i<n; i++) {
            freq.merge(nums[i], 1, Integer::sum);
            while(freq.size() == dist) {
                ans += (n - i);
                freq.put(nums[j], freq.get(nums[j]) - 1);
                if(freq.get(nums[j]) == 0) freq.remove(nums[j]);
                j++;
            }
        }

        return ans;
    }
}