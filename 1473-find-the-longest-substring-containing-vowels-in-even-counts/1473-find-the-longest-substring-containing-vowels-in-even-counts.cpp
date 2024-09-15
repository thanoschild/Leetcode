class Solution {
public:
    int findTheLongestSubstring(string s) {
        map<int, int> mp;
        mp[0] = -1;
        string v = "aeiou";
        int mask = 0, ans = 0;

        for(int i = 0; i<s.size(); i++) {
            for(int j = 0; j<5; j++) {
                if(s[i] == v[j]) {
                    mask = mask ^ (1 << j);
                    break;
                }
            }

            if(mp.find(mask) == mp.end()) {
                mp[mask] = i;
            }
            ans = max(ans, i - mp[mask]);
        }

        return ans;
    }
};