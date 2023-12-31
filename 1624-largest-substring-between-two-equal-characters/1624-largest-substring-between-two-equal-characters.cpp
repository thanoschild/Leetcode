class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        vector<int> freq(26, -1);
        int ans = -1;
        for(int i = 0; i<s.size(); i++) {
            if(freq[s[i] - 'a'] != -1) {
                ans = max(ans, i - freq[s[i] - 'a'] - 1);
                continue;
            }
            freq[s[i] - 'a'] = i;
        }

        return ans;
    }
};