class Solution {
    private void dfs(List<List<Integer>> adj, int root, int parent, int[] count, int[] ans) {
        for(int node : adj.get(root)) {
            if(node == parent) continue;
            dfs(adj, node, root, count, ans);
            count[root] += count[node];
            ans[root] += ans[node] + count[node];
        }
        count[root] += 1;
    }

    private void dfs2(List<List<Integer>> adj, int root, int parent, int[] count, int[] ans) {
        for(int node : adj.get(root)) {
            if(node == parent) continue;
            ans[node] = ans[root] - count[node] + count.length - count[node];
            dfs2(adj, node, root, count, ans);
        }
    }

    public int[] sumOfDistancesInTree(int n, int[][] edges) {
        int[] count = new int[n];
        int[] ans = new int[n];
        List<List<Integer>> adj = new ArrayList<>(n);
        for(int i = 0; i<n; i++) adj.add(new ArrayList<>());

        for(int[] edge : edges) {
            adj.get(edge[0]).add(edge[1]);
            adj.get(edge[1]).add(edge[0]);
        }

        dfs(adj, 0, -1, count, ans);
        dfs2(adj, 0, -1, count, ans);
        return ans;
    }
}