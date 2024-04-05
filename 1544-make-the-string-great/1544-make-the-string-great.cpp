class Solution {
public:
    string makeGood(string s) {
        string ans = "";
        for(int i = 0; i<s.size(); i++) {
            if(ans != "" && abs(ans.back() - s[i]) == 32) {
                ans.pop_back();
            }
            else {
                ans += s[i];
            }
        }

        return ans;
    }
};