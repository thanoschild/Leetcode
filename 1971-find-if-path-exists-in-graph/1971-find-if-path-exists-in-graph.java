class Solution {
    private void dfs(List<List<Integer>> edges, boolean[] seen, int idx, int dist) {
        seen[idx] = true;
        if(seen[dist]) return;

        for(int it : edges.get(idx)) {
            if(!seen[it]) dfs(edges, seen, it, dist);
        }
    }
    
    public boolean validPath(int n, int[][] edges, int source, int destination) {
        boolean[] seen = new boolean[n];
        List<List<Integer>> adj = new ArrayList<>();
        for(int i = 0; i<n; i++) {
            adj.add(new ArrayList<>());
        }

        for(int i = 0; i<edges.length; i++) {
            adj.get(edges[i][0]).add(edges[i][1]);
            adj.get(edges[i][1]).add(edges[i][0]);
        }

        dfs(adj, seen, source, destination);
        return seen[destination];
    }
}