class Solution {
    public int findMaxLength(int[] nums) {
        int n = nums.length;
        HashMap<Integer, Integer> mp = new HashMap<>();
        int sum = 0, maxLen = 0;
        mp.put(0, -1);

        for(int i = 0; i<n; i++) {
            sum += nums[i] == 0 ? -1 : 1;
            if(mp.containsKey(sum)) {
                maxLen = Math.max(maxLen, i - mp.get(sum));
            }
            else mp.put(sum, i);
        }

        return maxLen;
    }
}