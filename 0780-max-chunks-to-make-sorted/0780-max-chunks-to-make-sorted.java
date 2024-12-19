class Solution {
    public int maxChunksToSorted(int[] arr) {
        int n = arr.length;
        int ans = 0, maxVal = 0;

        for(int i = 0; i<n; i++) {
            maxVal = Math.max(maxVal, arr[i]);
            if(maxVal == i) ans++;
        }

        return ans;
    }
}