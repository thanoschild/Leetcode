class Solution {
    public List<Integer> luckyNumbers (int[][] mat) {
        int n = mat.length, m = mat[0].length;
        int[] minRow = new int[n];
        int[] maxCol = new int[m];
        Arrays.fill(minRow, Integer.MAX_VALUE);
        Arrays.fill(maxCol, Integer.MIN_VALUE);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                minRow[i] = Math.min(minRow[i], mat[i][j]);
                maxCol[j] = Math.max(maxCol[j], mat[i][j]);
            }
        }

        List<Integer> ans = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (minRow[i] == maxCol[j]) {
                    ans.add(minRow[i]);
                    break;
                }
            }
        }

        return ans;
    }
}