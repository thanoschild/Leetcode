class Solution {
    private void dfs(int[] nums, int idx, HashMap<Integer, Integer> mp, int[] ans, int k) {
        if (idx == nums.length) {
            ans[0]++;
            return;
        }

        if (!mp.containsKey(nums[idx] - k) || mp.get(nums[idx] - k) == 0) {
            if (!mp.containsKey(nums[idx] + k) || mp.get(nums[idx] + k) == 0) {
                mp.put(nums[idx], mp.getOrDefault(nums[idx], 0) + 1);
                dfs(nums, idx + 1, mp, ans, k);
                mp.put(nums[idx], mp.get(nums[idx]) - 1);
            }
        }
        dfs(nums, idx + 1, mp, ans, k);
    }

    public int beautifulSubsets(int[] nums, int k) {
        int[] ans = new int[1];  // Use array to simulate pass-by-reference for the answer
        HashMap<Integer, Integer> mp = new HashMap<>();
        dfs(nums, 0, mp, ans, k);
        return ans[0] - 1;
    }
}