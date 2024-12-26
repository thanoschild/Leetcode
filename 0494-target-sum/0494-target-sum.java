class Solution {
    private Map<Integer, Map<Integer, Integer>> mp;

    private int findTarget(int[] nums, int sum, int target, int idx) {
        int n = nums.length;
        if(idx == n) {
            if(sum == target) return 1;
            else return 0;
        }

        if(mp.containsKey(idx) && mp.get(idx).containsKey(sum)) {
            return mp.get(idx).get(sum);
        }

        int ans = 0;
        mp.putIfAbsent(idx, new HashMap<>());
        ans += findTarget(nums, sum - nums[idx], target, idx + 1);
        ans += findTarget(nums, sum + nums[idx], target, idx + 1);
        
        mp.get(idx).put(sum, ans);
        return ans;
    }

    public int findTargetSumWays(int[] nums, int target) {
        mp = new HashMap<>();
        return findTarget(nums, 0, target, 0);
    }
}