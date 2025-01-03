class Solution {
    public int waysToSplitArray(int[] nums) {
        int n = nums.length;
        long left = 0L;
        List<Long> prefix = new ArrayList<>();
        for(int i = 0; i<n; i++) {
            left += nums[i];
            prefix.add(left);
        }

        int ans = 0;
        long right = 0L;
        left = 0L;
        for(int i = n - 1; i>0; i--) {
            right += nums[i];
            left = i > 0 ? prefix.get(i-1) : 0;
            if(left >= right) ans++;
        }

        return ans;
    }
}