class Solution {
public:
    bool check(string &a, string &b) {
        int n = a.size(), m = b.size();
        if(a > b) return false;

        return b.substr(0, n) == a && b.substr(m - n) == a;
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