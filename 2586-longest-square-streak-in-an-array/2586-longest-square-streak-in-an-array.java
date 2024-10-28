class Solution {
    public int longestSquareStreak(int[] nums) {
        int n = nums.length, ans = 0;
        HashMap<Integer, Integer> mp = new HashMap<>();
        Arrays.sort(nums);

        for(int it : nums) {
            int root = (int) Math.sqrt(it);
            if(root * root == it) {
                mp.put(it, mp.getOrDefault(root, 0) + 1);
            } else {
                mp.put(it, 1);
            }
            ans = Math.max(ans, mp.get(it));
        }

        return ans < 2 ? -1 : ans;
    }
}