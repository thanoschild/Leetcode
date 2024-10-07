class Solution {
public:
    int minLength(string s) {
        string ans = "";
        for(char c : s) {
            if(ans.size() > 0 && ((c == 'B' && ans[ans.size()-1] == 'A') || (c == 'D' && ans[ans.size()-1] == 'C'))) {
                ans.pop_back();
            } else ans += c;
        }

        return ans.size();
    }
};