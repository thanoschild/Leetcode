class Solution {
    public int minFallingPathSum(int[][] mat) {
        int n = mat.length;
        for(int i = 1; i<n; i++) {
            for(int j = 0; j<n; j++) {
                mat[i][j] += Math.min(mat[i-1][j], Math.min(mat[i-1][Math.max(0, j - 1)], mat[i-1][Math.min(n-1, j + 1)]));
            }
        }

        return Arrays.stream(mat[n-1]).min().getAsInt();
    }
}