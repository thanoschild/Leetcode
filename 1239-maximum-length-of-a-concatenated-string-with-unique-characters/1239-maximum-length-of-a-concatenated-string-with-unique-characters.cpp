class Solution {
public:
    int maxLength(vector<string>& arr) {
        vector<bitset<26>> dp;
        dp.push_back(bitset<26>());
        int ans = 0;
        for(auto s : arr) {
            bitset<26> st;
            for(char c : s) {
                st.set(c - 'a');
            }
            if(st.count() < s.size()) continue;

            for(int i = dp.size() - 1; i>=0; i--) {
                bitset c = dp[i];
                if((c & st).any()) continue;
                dp.push_back((c | st));
                ans = max(ans, (int)c.count() + (int)st.count());
            }
        }

        return ans;
    }
};