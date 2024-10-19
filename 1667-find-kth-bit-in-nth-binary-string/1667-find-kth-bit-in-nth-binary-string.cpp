class Solution {
public:
    void solve(int n, string &s) {
        if(n == 0) return;

        string newS = s;
        int mid = s.size()/2;
        if(newS[mid] == '0') newS[mid] = '1';
        else newS[mid] = '0';

        s += '1';
        s += newS;
        solve(n-1, s);
    }

    char findKthBit(int n, int k) {
        string s = "0";
        solve(n-1, s);
        return s[k-1];
    }
};