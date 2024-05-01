class Solution {
public:
    string reversePrefix(string word, char ch) {
        string ans = "";
        bool flag = true;
        for(char c : word) {
            if(c == ch && flag) {
                ans += c;
                reverse(ans.begin(), ans.end());
                flag = false;
            }
            else {
                ans += c;
            }
        }

        return ans;
    }
};