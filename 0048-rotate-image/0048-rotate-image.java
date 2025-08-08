class Solution {
    private void reverse(int[] arr, int n) {
        int left = 0, right = n - 1;

        while(left < right) {
            int temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;

            left++; right--;
        }
    }

    public void rotate(int[][] matrix) {
        int n = matrix.length;
        for(int i = 0; i<n; i++) {
            for(int j = i; j<n; j++) {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }

        for(int i = 0; i<n; i++) {
            reverse(matrix[i], n);
        }
    }
}