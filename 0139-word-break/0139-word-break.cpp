class Solution {
public:
    int find_max_len(vector<string> &dict) {
        int max_len = 0;
        for(string s : dict) {
            max_len = max(max_len, (int) s.size());
        }
        return max_len;
    }
    
    bool wordBreak(string s, vector<string>& dict) {
        int n = s.size();
        int m = dict.size();
        if(m == 0) return false;
        int max_len = find_max_len(dict);
        unordered_set<string> st(dict.begin(), dict.end());
        vector<bool> dp(n+1, 0);
        dp[0] = 1;

        for(int i = 1; i<=n; i++) {
            for(int j = i-1; j>=0 && j - i < max_len; j--) {
                if(dp[j]) {
                    if(st.count(s.substr(j, i-j))) dp[i] = 1;
                }
            }
        }

        return dp[n];
    }
};