class Solution {
public:
    int numSteps(string s) {
        int n = s.size(), ans = 0, carry = 0;
        for(int i = n - 1; i>0; i--) {
            if(s[i] - '0' + carry == 1) {
                ans++;
                carry = 1;
            }
            ans++;
        }

        return ans + carry;
    }
};