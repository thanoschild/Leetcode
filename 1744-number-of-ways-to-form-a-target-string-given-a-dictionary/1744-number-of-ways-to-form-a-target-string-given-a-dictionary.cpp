class Solution {
public:
    const int mod = 1e9 + 7;
    int numWays(vector<string>& words, string target) {
        int n = words[0].size(), m = target.size();
        vector<unordered_map<char, int>> freq(n);
        for(string s : words) {
            for(int i = 0; i<s.size(); i++) freq[i][s[i]]++;
        }

        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        function<int(int, int)> solve = [&](int level, int idx) -> int {
            if(idx == m) return 1;
            if(level == n) return 0;

            if(dp[level][idx] != -1) return dp[level][idx];
            int count = solve(level + 1, idx);

            if(freq[level].count(target[idx])) {
                long long curr = freq[level][target[idx]];
                count = (count + curr * solve(level + 1, idx + 1)) % mod;
            }

            return dp[level][idx] = count;
        };

        return solve(0, 0);
    }
};