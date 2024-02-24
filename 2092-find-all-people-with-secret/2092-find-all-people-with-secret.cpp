class UnionFind {
public:
    vector<int> parent;
    vector<int> sz;

    UnionFind(int n) {
       parent.resize(n);
       sz.resize(n);

       for(int i = 0; i<n; i++) {
           parent[i] = i;
           sz[i] = 1;
       }
    }
    
    int find_parent(int x) {
        if(x == parent[x]) return x;
        return parent[x] = find_parent(parent[x]);
    }

    void make_union(int x, int y) {
        int a = find_parent(x);
        int b = find_parent(y);
        if(a != b) {
            if(sz[b] > sz[a]) swap(a, b);
            parent[b] = a;
            sz[a] += sz[b];
        }
    }

    void reset(int x) {
        parent[x] = x;
    }
       
};

class Solution {
public:
    
    vector<int> findAllPeople(int n, vector<vector<int>>& meet, int firstPerson) {
        UnionFind uf(n);
        sort(meet.begin(), meet.end(), [](auto &a, auto &b){return a[2] < b[2];});
        vector<int> people;
        int m = meet.size();
        uf.make_union(0, firstPerson);

        for(int i = 0; i<m;) {
            people.clear();
            int time = meet[i][2];
            for(; i<m && meet[i][2] == time; i++) {
                int a = meet[i][0], b = meet[i][1];
                uf.make_union(a, b);
                people.push_back(a);
                people.push_back(b);
            }

            for(int x : people) {
                if(uf.find_parent(x) !=uf.find_parent(0)) {
                    uf.reset(x);
                }
            }
        }

        vector<int> ans;
        for(int i = 0; i<n; i++) {
            if(uf.find_parent(0) == uf.find_parent(i)) ans.push_back(i);
        }

        return ans;
    }
};