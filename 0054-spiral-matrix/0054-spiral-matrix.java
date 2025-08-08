class Solution {
    public List<Integer> spiralOrder(int[][] matrix) {
        int n = matrix.length, m = matrix[0].length;
        int r1 = 0, r2 = n - 1, c1 = 0, c2 = m - 1;
        List<Integer> ans = new ArrayList<>();

        while(r1 <= r2 && c1 <= c2) {
            for(int i = c1; i<=c2; i++) {
                ans.add(matrix[r1][i]);
            }
            r1++;
            if(r1 > r2) break;

            for(int i = r1; i<=r2; i++) {
                ans.add(matrix[i][c2]);
            }
            c2--;
            if(c1 > c2) break;

            for(int i = c2; i>=c1; i--) {
                ans.add(matrix[r2][i]);
            }
            r2--;
            if(r1 > r2) break;

            for(int i = r2; i>=r1; i--) {
                ans.add(matrix[i][c1]);
            }
            c1++;
            if(c1 > c2) break;
        }

        return ans;
    }
}