class Solution {
public:
    class dsu {
        public:
        vector<int> parent, sz;
        dsu(int n){
            parent.resize(n);
            sz.resize(n);
            for(int i = 0; i<n; i++){
                parent[i] = i;
                sz[i] = 1;
            }
        }

        int find_set(int x) {
            if(parent[x] == x) return x;
            return parent[x] = find_set(parent[x]);
        }

        bool make_union(int x, int y) {
            int a = find_set(x);
            int b = find_set(y);
            if(a == b) return false;
            if(sz[a] < sz[b]) swap(a, b);
            parent[b] = a;
            sz[a] += sz[b];
            return true;
        }

        int count(int x) {
            return sz[x];
        }
    };
    int maxNumEdgesToRemove(int n, vector<vector<int>> &edges) {
         vector<pair<int,int>> alice, bob, both;
         for(int i = 0; i<edges.size(); i++){
             int t = edges[i][0];
             int x = edges[i][1]-1;
             int y = edges[i][2]-1;
             if(t == 3){
                 both.push_back({x, y});
             }
             else if(t == 2){
                 bob.push_back({x, y});
             }
             else{
                 alice.push_back({x, y});
             }
         }

         dsu a(n), b(n);
         int ans = 0;
         for(auto it : both){
             ans += a.make_union(it.first, it.second);
             b.make_union(it.first, it.second);
         }
         for (auto it : alice){
             ans += a.make_union(it.first, it.second); 
         }
         for (auto it : bob){
             ans += b.make_union(it.first, it.second);     
         }
         if(a.count(a.find_set(0)) < n || b.count(b.find_set(0)) < n) return -1;
         return edges.size() - ans;
    }
};