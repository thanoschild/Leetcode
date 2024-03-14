class Solution {
    public int numSubarraysWithSum(int[] nums, int goal) {
        HashMap<Integer, Integer> mp = new HashMap<>();
        mp.put(0, 1);
        int ans = 0, sum = 0;
        for(int it : nums) {
            sum += it;
            ans += mp.getOrDefault(sum - goal, 0);
            mp.put(sum, mp.getOrDefault(sum, 0) + 1);
        }

        return ans;
    }
}