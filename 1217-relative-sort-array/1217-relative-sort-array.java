class Solution {
    public int[] relativeSortArray(int[] arr1, int[] arr2) {
        int[] freq = new int[1001];
        for(int n : arr1) freq[n]++;
        int i = 0;
        for(int n : arr2) while(freq[n]-- > 0) arr1[i++] = n;
        for(int j = 0; j<1001; j++) while(freq[j]-- > 0) arr1[i++] = j;
        return arr1;
    }
}