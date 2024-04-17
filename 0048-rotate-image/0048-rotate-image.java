class Solution {
    private void reverse(int[] arr, int n) {
        int left = 0;
        int right = arr.length - 1;
        
        while (left < right) {
            int temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;
  
            left++;
            right--;
        }
    }

    public void rotate(int[][] mat) {
        int n = mat.length;
        for(int i = 0; i<n; i++) {
            for(int j = i; j<n; j++) {
                int temp = mat[i][j];
                mat[i][j] = mat[j][i];
                mat[j][i] = temp;
            }
        }

        for(int i = 0; i<n; i++) {
            reverse(mat[i], n);
        }
    }
}