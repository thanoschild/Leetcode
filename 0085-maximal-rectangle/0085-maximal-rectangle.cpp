class Solution {
public:
    int maximalRectangle(vector<vector<char>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int dp[n][m+1];
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(i == 0){
                    dp[i][j] = mat[i][j] - '0';
                }
                else{
                    if(mat[i][j] == '0') dp[i][j] = 0;
                    else{
                        dp[i][j] = dp[i-1][j] + 1;
                    } 
                }
            }
        }
        
        for(int i = 0; i<n; i++){
            dp[i][m] = 0;
        }
        
        int ans = 0;
        for(int i = 0; i<n; i++){
            stack<int> st;
            for(int j = 0; j<m+1; j++){
                while(!st.empty() && dp[i][st.top()] > dp[i][j]){
                    int h = dp[i][st.top()];
                    st.pop();
                    if(st.empty()){
                        ans = max(ans, h*j);
                    }
                    else{
                        int len = j - st.top() - 1;
                        ans = max(ans, len*h);
                    }
                }
                st.push(j);
            }
        }
        
        return ans;
    }
};