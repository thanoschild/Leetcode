class Solution {
public:
    int dfs(string s, vector<int> &dp, unordered_map<string, int> &mp, int idx) {
        if(idx >= s.size()) return 0;
        if(dp[idx] != -1) return dp[idx];

        int minlen = s.size();
        string str = "";
        for(int i = idx; i<s.size(); i++) {
           str += s[i];
           int count = mp.count(str) ? 0 : str.size();
           int newCount = dfs(s, dp, mp, i+1);
           minlen = min(minlen, count + newCount);
        } 

        return dp[idx] = minlen;
    }

    int minExtraChar(string s, vector<string>& dictionary) {
        vector<int> dp(s.size(), -1);
        unordered_map<string, int> mp;
        for(string it : dictionary) mp[it]++;
        return dfs(s, dp, mp, 0);
    }
};