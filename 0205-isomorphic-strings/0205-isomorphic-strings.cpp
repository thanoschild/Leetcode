class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size() != t.size()) return false;
        int map_s[256] = {0};
        int map_t[256] = {0};
       
        for(int i = 0; i<s.size(); i++) {
            if(map_s[s[i]] != map_t[t[i]]) return false;
            map_s[s[i]] = i + 1;
            map_t[t[i]] = i + 1;
        }

        return true;
    }
};