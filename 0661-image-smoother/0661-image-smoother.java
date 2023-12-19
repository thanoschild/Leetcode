class Solution {
    int solve(int[][] img, int x, int y) {
        int n = img.length;
        int m = img[0].length;
        int sum = 0, count = 0;
        
        for(int i = -1; i<=1; i++) {
            for(int j = -1; j<=1; j++) {
                int dx = x + i;
                int dy = y + j;
                if(dx >= 0 && dx < n && dy >= 0 && dy < m) {
                    sum += img[dx][dy];
                    count++;
                }
            }
        }
        
        return sum/count;
    }
    
    public int[][] imageSmoother(int[][] img) {
        int n = img.length;
        int m = img[0].length;
        int[][] ans = new int[n][m];
        
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<m; j++) {
                ans[i][j] = solve(img, i, j);
            }
        }
        return ans;
    }
}