class Solution {
public:
    vector<int> parent;
    int findParent(int x) {
        if(parent[x] == x) return x;
        return parent[x] = findParent(parent[x]);
    }
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        parent.resize(n+1);
        for(int i = 0; i<=n; i++) {
           parent[i] = i;
        }

        for(auto it : edges) {
            int x = it[0], y = it[1];
            int a = findParent(x);
            int b = findParent(y);
            if(a == b) return {x, y};
            parent[b] = a;
        }

        return {};
    }
};