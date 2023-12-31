class Solution {
public:
    int maximumLength(string s) {
        map<string, int> mp;
        int n = s.size();

        
        for(int i = 0; i<n; i++) {
            string curr = "";
            curr += s[i];
            mp[curr]++;
          
            for(int j = i; j<n-1; j++) {
                if(s[j] == s[j+1]) {
                    curr += s[j];
                    mp[curr]++;
                }
                else break;
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