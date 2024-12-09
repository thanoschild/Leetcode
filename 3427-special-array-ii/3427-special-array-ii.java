class Solution {
    public boolean[] isArraySpecial(int[] nums, int[][] queries) {
        int n = nums.length, m = queries.length;
        int[] prefix = new int[n];
        for(int i = 1; i<n; i++) {
            prefix[i] = prefix[i-1];
            if((nums[i]%2 == 0 && nums[i-1]%2 == 0) || (nums[i]%2 == 1 && nums[i-1]%2 == 1)) {
                prefix[i]++;
            }
        }

        boolean[] ans = new boolean[m];
        for(int i = 0; i<m; i++) {
            int count = prefix[queries[i][1]] - prefix[queries[i][0]];
            ans[i] = count == 0 ? true : false;
        }

        return ans;
    }
}