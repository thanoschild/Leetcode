class Solution {
    public int findJudge(int n, int[][] trust) {
        int[] indeg = new int[n+1];
        for(int i = 0; i<trust.length; i++) {
            indeg[trust[i][0]]--;
            indeg[trust[i][1]]++;
        }

        for(int i = 1; i<=n; i++) {
            if(indeg[i] == n - 1) return i;
        }

        return -1;
    }
}