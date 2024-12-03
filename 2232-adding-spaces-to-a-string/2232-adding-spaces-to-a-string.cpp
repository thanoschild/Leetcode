class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string ans;
        int n = s.size(), m = spaces.size(), idx = 0;

        if(m > 0 && spaces[idx] == 0) {
            ans += " ";
            idx++;
        }

        for(int i = 0; i<n; i++) {
            ans += s[i];
            if(idx < m && i+1 == spaces[idx]) {
                ans += " ";
                idx++;
            }
        }

        return ans;
    }
};