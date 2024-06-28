class Solution {
    public long maximumImportance(int n, int[][] roads) {
        int[] indegree = new int[n];
        for(int[] x : roads) {
            indegree[x[0]]++;
            indegree[x[1]]++;
        }

        Arrays.sort(indegree);
        long ans = 0, val = 1;
        for(int x : indegree) {
            ans += (x * val);
            val++;
        }

        return ans;
    }
}