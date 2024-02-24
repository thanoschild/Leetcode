class UnionFind {
    int[] parent;
    int[] sz;

    UnionFind(int n) {
        parent = new int[n];
        sz = new int[n];

        for(int i = 0; i<n; i++) {
            parent[i] = i;
            sz[i] = 1;
        }
    }

    int findParent(int x) {
        if(parent[x] == x) return x;
        return parent[x] = findParent(parent[x]);
    }

    void makeUnion(int x, int y) {
        int a = findParent(x);
        int b = findParent(y);
        if(a != b) {
            if(sz[b] > sz[a]) {
                int temp = a;
                a = b;
                b = temp;
            }
            parent[b] = a;
            sz[a] += sz[b];
        }
    }

    void reset(int x) {
        parent[x] = x;
    }
}

class Solution {
    public List<Integer> findAllPeople(int n, int[][] meet, int firstPerson) {
        UnionFind uf = new UnionFind(n);
        Arrays.sort(meet, (a, b) -> a[2] - b[2]);
        uf.makeUnion(0, firstPerson);
        List<Integer> people = new ArrayList<>();
        int m = meet.length;

        for(int i = 0; i<m;) {
            people.clear();
            int time = meet[i][2];
            for(; i<m && meet[i][2] == time; i++) {
                int a = meet[i][0], b = meet[i][1];
                uf.makeUnion(a, b);
                people.add(a);
                people.add(b);
            }

            for (int x : people) {
                if (uf.findParent(x) != uf.findParent(0)) {
                    uf.reset(x);
                }
            }
        }

        List<Integer> ans = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            if (uf.findParent(0) == uf.findParent(i)) ans.add(i);
        }

        return ans;
    }
}