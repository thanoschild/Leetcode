class Solution {
    public String[] findRelativeRanks(int[] score) {
        int n = score.length;
        int[][] pair = new int[n][2];
        for(int i = 0; i<n; i++) {
            pair[i][0] = score[i];
            pair[i][1] = i;
        }

        Arrays.sort(pair, (a, b) -> (b[0] - a[0]));
        String[] ans = new String[n];

        for(int i = 0; i<n; i++) {
            if(i == 0) {
                ans[pair[i][1]] = "Gold Medal";
            }
            else if(i == 1) {
                ans[pair[i][1]] = "Silver Medal";
            }
            else if(i == 2) {
                ans[pair[i][1]] = "Bronze Medal";
            }
            else {
                ans[pair[i][1]] = String.valueOf(i + 1);
            }
        }

        return ans;
    }
}