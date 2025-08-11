class Solution {
    public int[] productQueries(int n, int[][] queries) {
        List<Integer> powers = new ArrayList<>();
        for(int i = 0; i<31; i++) {
            if((n >> i & 1) == 1) powers.add(1 << i);
        }

        int mod = (int) 1e9 + 7;
        int len = queries.length;
        int[] ans = new int[len];

        for(int i = 0; i<len; i++) {
            int start = queries[i][0];
            int end = queries[i][1];
            long pro = powers.get(start++);
            while(start <= end) {
                pro = (pro * powers.get(start)) % mod;
                start++;
            }
            ans[i] = (int) pro;
        }

        return ans;
    }
}