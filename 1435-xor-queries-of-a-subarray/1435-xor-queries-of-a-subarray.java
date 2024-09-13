class Solution {
    public int[] xorQueries(int[] arr, int[][] queries) {
        int n = arr.length, m = queries.length;
        int[] xors = new int[n];
        int _xor = 0;

        for(int i = 0; i<n; i++) {
           _xor ^= arr[i];
           xors[i] = _xor;
        }

        int[] ans = new int[m];
        for(int i = 0; i<m; i++) {
            int start = queries[i][0];
            int end = queries[i][1];

            if(start == 0) ans[i] = xors[end];
            else ans[i] = xors[end] ^ xors[start - 1];
        }

        return ans;
    }
}