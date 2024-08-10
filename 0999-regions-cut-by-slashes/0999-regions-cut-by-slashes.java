class Solution {
    int[] parent;
    int[] sz;

    private int findSet(int x) {
        if(parent[x] == x) return x;
        return parent[x] = findSet(parent[x]);
    }

    private boolean makeUnion(int x, int y) {
        int a = findSet(x);
        int b = findSet(y);
        if(a == b) return true;

        if(sz[b] > sz[a]) {
            int temp = a;
            a = b;
            b = temp;
        }
        parent[b] = a;
        sz[a] += sz[b];
        return false; 
    }

    public int regionsBySlashes(String[] grid) {
        int n = grid.length+1;
        parent = new int[n*n];
        sz = new int[n*n];

        for(int i = 0; i<n*n; i++) {
            parent[i] = i;
            sz[i] = 1;
        }

        for(int i = 0; i<n; i++) {
            for(int j = 0; j<n; j++) {
                if(i == 0 || j == 0 || i == n - 1 || j == n - 1) {
                    int x = i*n + j;
                    makeUnion(0, x);
                }
            }
        }

        int ans = 1;
        for(int i = 0; i<n-1; i++) {
            String s = grid[i];
            for(int j = 0; j<s.length(); j++) {
                char c = s.charAt(j);
                if(c == '/') {
                    int x = (i + 1) * n + j;
                    int y = i*n + (j + 1);
                    if(makeUnion(x, y)) ans++;
                }
                else if(c == '\\') {
                    int x = i*n + j;
                    int y = (i + 1)*n + (j + 1);
                    if(makeUnion(x, y)) ans++;
                }
            }
        }

        return ans;
    }
}