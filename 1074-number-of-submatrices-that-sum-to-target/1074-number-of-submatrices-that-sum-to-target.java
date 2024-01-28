class Solution {
    public int numSubmatrixSumTarget(int[][] mat, int target) {
        int n = mat.length; int m = mat[0].length;
        for(int i = 0; i<n; i++) {
            for(int j = 1; j<m; j++) {
                mat[i][j] += mat[i][j-1];
            }
        }

        int ans = 0;
        for(int i = 0; i<m; i++) {
            for(int col = i; col < m; col++) {
                HashMap<Integer, Integer> mp = new HashMap<>();
                mp.put(0, 1);
                int sum = 0;
                for(int row = 0; row<n; row++) {
                    sum += mat[row][col] - (i > 0 ? mat[row][i-1] : 0);
                    ans += mp.getOrDefault(sum - target, 0);
                    mp.put(sum, mp.getOrDefault(sum, 0) + 1);
                }
            }
        }

        return ans;
    }
}