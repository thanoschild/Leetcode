class Solution {
    public boolean checkGrid(int i, int j, int[][] grid) {
        int[] counts = new int[10]; 

        for (int k = i; k < i + 3; k++) {
            int sumRows = 0;
            for (int l = j; l < j + 3; l++) {
                sumRows += grid[k][l];
                if (grid[k][l] < 1 || grid[k][l] > 9) return false;
                counts[grid[k][l]]++;
            }
            if (sumRows != 15) return false;
        }

        for (int k = j; k < j + 3; k++) {
            int sumCols = 0;
            for (int l = i; l < i + 3; l++) {
                sumCols += grid[l][k];
            }
            if (sumCols != 15) return false;
        }

        int leftd = 0, rightd = 0;
        for (int k = 0; k < 3; k++) {
            leftd += grid[i + k][j + k];
            rightd += grid[i + k][j + 2 - k];
        }

        if (leftd != 15 || rightd != 15) return false;

        for (int k = 1; k <= 9; k++) {
            if (counts[k] != 1) return false;
        }

        return true;
    }

    public int numMagicSquaresInside(int[][] grid) {
        int n = grid.length, m = grid[0].length;
        if (n < 3 || m < 3) return 0;
        int ans = 0;

        for (int i = 0; i <= n - 3; i++) {
            for (int j = 0; j <= m - 3; j++) {
                if (checkGrid(i, j, grid)) ans++;
            }
        }

        return ans;
    }
}