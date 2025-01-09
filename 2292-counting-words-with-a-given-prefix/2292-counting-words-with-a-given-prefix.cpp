class Solution {
public:
    bool check(string word, string prefix) {
        int n = word.size(), m = prefix.size();
        if(m > n) return false;
        for(int i = 0; i<m; i++) {
            if(word[i] != prefix[i]) return false;
        }
        return true;
    }
    
    int prefixCount(vector<string>& words, string pref) {
        int n = words.size(), ans = 0;
        for(string word : words) {
            if(check(word, pref)) ans++;
        }

        return ans;
    }
};