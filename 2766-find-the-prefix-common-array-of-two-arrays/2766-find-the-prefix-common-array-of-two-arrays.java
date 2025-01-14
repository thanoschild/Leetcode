class Solution {
    public int[] findThePrefixCommonArray(int[] A, int[] B) {
        int n = A.length, count = 0;
        int[] freq = new int[n+1];
        int[] ans = new int[n];

        for(int i = 0; i<n; i++) {
            if(++freq[A[i]] == 2) count++;
            if(++freq[B[i]] == 2) count++;
            ans[i] = count;
        }

        return ans;
    }
}