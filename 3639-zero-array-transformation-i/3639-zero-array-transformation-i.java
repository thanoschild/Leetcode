class Solution {
    public boolean isZeroArray(int[] nums, int[][] queries) {
        int n = nums.length, m = queries.length;
        int[] freq = new int[n+1];

        for(int i = 0; i<m; i++) {
            int l = queries[i][0], r = queries[i][1];
            freq[l] += 1;
            freq[r+1] -= 1;
        }

        for(int i = 1; i<=n; i++) {
            freq[i] += freq[i-1];
        }

        for(int i = 0; i<n; i++) {
            if(freq[i] < nums[i]) return false;
        }

        return true;
    }
}