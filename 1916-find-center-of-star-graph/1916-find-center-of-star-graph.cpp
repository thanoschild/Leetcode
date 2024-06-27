class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> adj(n+1, 0);
        int maxIndegree = 0, node = -1;
        for(auto it : edges) {
           adj[it[0]-1]++;
           adj[it[1]-1]++;

           if(maxIndegree < adj[it[0]-1]) {
              maxIndegree = adj[it[0]-1];
              node = it[0];
           }
           if(maxIndegree < adj[it[1]-1]) {
              maxIndegree = adj[it[1]-1];
              node = it[1];
           }
        }

        return node;
    }
};