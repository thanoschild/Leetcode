class Solution {
public:
    string clearDigits(string s) {
        string ans = "";
        for(char c : s) {
            if(isdigit(c) && ans.size() > 0) ans.pop_back();
            else ans.push_back(c);
        }

        return ans;
    }
};