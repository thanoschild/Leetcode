class Solution {
    public int findTheCity(int n, int[][] edges, int distanceThreshold) {
        int[][] dist = new int[n][n];
        int small = n;

        // Initialize distances with a large value
        for (int[] row : dist) {
            Arrays.fill(row, 10001);
        }

        // Set the distances for the given edges
        for (int[] edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            dist[u][v] = dist[v][u] = w;
        }

        // Set the distance from a node to itself to 0
        for (int i = 0; i < n; i++) {
            dist[i][i] = 0;
        }

        // Apply Floyd-Warshall algorithm to find all-pairs shortest paths
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    dist[i][j] = Math.min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }

        // Find the city with the smallest number of reachable cities within the given distance
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int count = 0;
            for (int j = 0; j < n; j++) {
                if (dist[i][j] <= distanceThreshold) {
                    count++;
                }
            }

            if (count <= small) {
                ans = i;
                small = count;
            }
        }

        return ans;
    }
}