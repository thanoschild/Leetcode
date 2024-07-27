class Solution {
    public long minimumCost(String source, String target, char[] original, char[] changed, int[] cost) {
        int n = source.length();
        int m = original.length;
        
        if (n != target.length()) {
            return -1;
        }

        long[][] dist = new long[26][26];
        for (long[] row : dist) {
            Arrays.fill(row, Integer.MAX_VALUE);
        }

        for (int i = 0; i < 26; i++) {
            dist[i][i] = 0;
        }

        for (int i = 0; i < m; i++) {
            int a = original[i] - 'a';
            int b = changed[i] - 'a';
            dist[a][b] = Math.min(dist[a][b], cost[i]);
        }

        for (int k = 0; k < 26; k++) {
            for (int i = 0; i < 26; i++) {
                for (int j = 0; j < 26; j++) {
                    if (dist[i][k] < Integer.MAX_VALUE && dist[k][j] < Integer.MAX_VALUE) {
                        dist[i][j] = Math.min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }

        long ans = 0;
        for (int i = 0; i < n; i++) {
            int a = source.charAt(i) - 'a';
            int b = target.charAt(i) - 'a';
            if (dist[a][b] == Integer.MAX_VALUE) return -1;
            ans += dist[a][b];
        }

        return ans;
    }
}