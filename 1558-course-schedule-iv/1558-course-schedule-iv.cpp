class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& pre, vector<vector<int>>& qr) {
       vector<vector<bool>> visited(n, vector<bool>(n,0));
       for(auto it : pre){
        visited[it[0]][it[1]] = true;
       }

       for(int k = 0; k<n; k++){
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                visited[i][j] = visited[i][j] || (visited[i][k] && visited[k][j]);
            }
        }
       }
       vector<bool> ans(qr.size());
       for(int i = 0; i<qr.size(); i++){
         ans[i] = visited[qr[i][0]][qr[i][1]];
       }

       return ans;
    }
};