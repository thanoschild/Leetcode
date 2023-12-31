class Solution {
public:
    int maximumLength(string s) {
        map<pair<char, int>, int> mp;
        int n = s.size();

        for(int i = 0; i<n; i++) {
            int count = 1;
            mp[{s[i], count}]++;
            for(int j = i; j<n - 1; j++) {
                if(s[j] == s[j+1]) {
                    count++;
                    mp[{s[i], count}]++;
                }
                else break;
            }
        }

        int ans = 0;
        for(auto it : mp) {
            if(it.second >= 3) {
                ans = max(ans, it.first.second);
            }
        }

        return ans == 0 ? -1 : ans;
    }
};