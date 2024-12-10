class Solution {
public:
    int maximumLength(string s) {
        unordered_map<string ,int> mp;
        int n = s.size();

        for(int i = 0; i<n; i++) {
            string str = "";
            str += s[i];
            mp[str]++;

            for(int j = i; j<n-1; j++) {
                if(s[j] == s[j+1]) {
                    str += s[j];
                    mp[str]++;
                } else break;
            }
        }

        int ans = 0;
        for(auto it : mp) {
            if(it.second >= 3) {
                ans = max(ans, (int)it.first.size());
            }
        }

        return ans == 0 ? -1 : ans;
    }
};