class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int zeros = 0, ones = 0;
        for(char c : s) {
            if(c == '0') zeros++;
            else ones++;
        }

        string ans = "";
        ones -= 1;
        while(ones-- > 0) ans += '1';
        while(zeros-- > 0) ans += '0';
        ans += '1';

        return ans;    
    }
};