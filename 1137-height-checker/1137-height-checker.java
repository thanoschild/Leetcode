class Solution {
    public int heightChecker(int[] heights) {
        int ans = 0, n = heights.length;
        int[] expected = new int[n];
        for(int i = 0; i<n; i++) {
            expected[i] = heights[i];
        }
        Arrays.sort(expected);
        for(int i = 0; i<n; i++) {
            if(heights[i] != expected[i]) ans++;
        }

        return ans;
    }
}