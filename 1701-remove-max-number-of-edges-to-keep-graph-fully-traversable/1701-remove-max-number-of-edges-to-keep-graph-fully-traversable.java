class Solution {
    class UnionFind {
        int[] parent, sz;
        public UnionFind(int n) {
            parent = new int[n];
            sz = new int[n];
            for(int i = 0; i<n; i++) {
                parent[i] = i;
                sz[i] = 1;
            }
        }

        public int findSet(int x) {
            if(parent[x] == x) return x;
            return parent[x] = findSet(parent[x]);
        }

        public int makeUnion(int x, int y) {
            int a = findSet(x);
            int b = findSet(y);
            if(a == b) return 0;
            if(sz[a] < sz[b]) {
                int temp = a;
                a = b;
                b = temp;
            }
            sz[a] += sz[b];
            parent[b] = a;
            return 1;
        }

        public int count(int x) {
            return sz[x];
        }
    }

    public int maxNumEdgesToRemove(int n, int[][] edges) {
        List<int[]> alice = new ArrayList<>();
        List<int[]> bob = new ArrayList<>();
        List<int[]> both = new ArrayList<>();
        for(int i = 0; i<edges.length; i++) {
            int t = edges[i][0];
            int x = edges[i][1] - 1;
            int y = edges[i][2] - 1;
            if(t == 3) {
                both.add(new int[]{x, y});
            }
            else if(t == 2) {
                bob.add(new int[]{x, y});
            }
            else {
                alice.add(new int[]{x, y});
            }
        }

        UnionFind a = new UnionFind(n);
        UnionFind b = new UnionFind(n);
        int requiredEdges = 0;
        for(int[] x : both) {
            requiredEdges += a.makeUnion(x[0], x[1]);
            b.makeUnion(x[0], x[1]);
        }

        for(int[] x : alice) {
            requiredEdges += a.makeUnion(x[0], x[1]);
        }

        for(int[] x : bob) {
            requiredEdges += b.makeUnion(x[0], x[1]);
        }
        
        if(a.count(a.findSet(0)) < n || b.count(b.findSet(0)) < n) return -1;

        return edges.length - requiredEdges;
    } 
}