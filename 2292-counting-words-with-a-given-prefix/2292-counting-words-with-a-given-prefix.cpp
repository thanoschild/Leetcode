class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int ans = 0, n = pref.size();
        for(string word : words) {
            if(word.substr(0, n) == pref) ans++;
        }

        return ans;
    }
};