class Solution {
    private int findParent(int x, int[] parent) {
        if(parent[x] == x) return x;
        return parent[x] = findParent(parent[x], parent);
    }

    public int[] findRedundantConnection(int[][] edges) {
        int n = edges.length;
        int[] parent = new int[n+1];
        for(int i = 0; i<=n; i++) parent[i] = i;

        for(int[] it : edges) {
            int x = it[0], y = it[1];
            int a = findParent(x, parent), b = findParent(y, parent);
            if(a == b) return new int[] {x, y};
            parent[b] = a;
        }

        return new int[] {};
    }
}