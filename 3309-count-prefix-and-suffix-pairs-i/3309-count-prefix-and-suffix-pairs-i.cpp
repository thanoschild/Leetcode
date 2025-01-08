class Solution {
public:
    bool check(string &a, string &b) {
        int n = a.size(), m = b.size();
        if(a > b) return false;

        for(int i = 0; i<n; i++) {
            if(a[i] != b[i]) return false;
        }

        for(int i = n - 1, j = m - 1; i>=0; i--, j--) {
            if(a[i] != b[j]) return false;
        }

        return true;
    }
    
    int countPrefixSuffixPairs(vector<string>& words) {
        int n = words.size();

        int ans = 0;
        for(int i = 0; i<n; i++) {
            for(int j = i + 1; j<n; j++) {
                if(check(words[i], words[j])) ans++;
            }
        }

        return ans;
    }
};