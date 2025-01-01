class Solution {
public:
    int maxScore(string s) {
        int ones = 0, zeros = 0, ans = INT_MIN;
        for(int i = 0; i<s.size(); i++) {
            if(s[i] == '0') zeros++;
            else ones++;
            if(i != s.size() - 1) ans = max(ans, zeros - ones);
        }
        
        return ans + ones;
    }
};
