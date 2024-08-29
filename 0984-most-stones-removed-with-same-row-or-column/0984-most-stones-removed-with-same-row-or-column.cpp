class Solution {
public:
    vector<int> parent;
    int find_set(int x){
        if(parent[x] == x) return x;
        return parent[x] = find_set(parent[x]);
    }

    bool make_union(int x, int y){
        int a = find_set(x);
        int b = find_set(y);
        if(a == b) return false;
        parent[a] = b;
        return true;
    }

    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        parent.resize(n);
        for(int i = 0; i<n; i++) parent[i] = i;

        int count = 0;
        for(int i = 0; i<n-1; i++){
            for(int j = i+1; j<n; j++){
                if(stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]){
                    if(make_union(i, j)) count++;
                }
            }
        }
        return count;
    }
};