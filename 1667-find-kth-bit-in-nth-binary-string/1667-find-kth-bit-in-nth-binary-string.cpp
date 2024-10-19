class Solution {
public:
    string invertString(string s) {
        for(int i = 0; i<s.size(); i++) {
            if(s[i] == '0') s[i] = '1';
            else s[i] = '0';
        }

        return s;
    }

    char findKthBit(int n, int k) {
        string s = "0";
        for(int i = 0; i<n; i++) {
            string invert = invertString(s);
            reverse(invert.begin(), invert.end());
            s = s + "1" + invert;
        }

        return s[k-1];
    }
};