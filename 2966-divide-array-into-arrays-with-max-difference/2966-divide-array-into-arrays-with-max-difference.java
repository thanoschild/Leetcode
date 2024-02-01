class Solution {
    public int[][] divideArray(int[] nums, int k) {
        int m = nums.length;
        if(m%3 != 0) return new int[0][0];

        int max = 0;
        for(int n : nums) max = Math.max(max, n);

        int[] freq = new int[max+1];
        for(int n : nums) freq[n]++;

        int[][] ans = new int[m/3][3];
        for(int n = 0, j = 0, i = 0; i<m/3 && n <= max;) {
            if(freq[n] == 0) n++;
            else if(j == 3) {
                j = 0; i++;
            }
            else if(j == 0 || n - ans[i][0] <= k) {
                ans[i][j] = n;
                freq[n]--;
                j++;
            }
            else return new int[0][0];
        }

        return ans;
    }
}