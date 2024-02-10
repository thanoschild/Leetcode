class Solution {
public:
    int solve(int i, int j, string s) {
        int count = 0;
        while(i >= 0 && j<s.size() && s[i] == s[j]) {
            i--, j++;
            count++;
        }

        return count;
    }
    
    int countSubstrings(string s) {
        int n = s.size(), ans = 0;
        for(int i = 0; i<n; i++) {
            int j = i;
            int odd = solve(i, j, s);
            int even = solve(i, j+1, s);
            ans += (odd + even);
        }

        return ans;
    }
};