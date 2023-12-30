class Solution {
public:
    bool makeEqual(vector<string>& words) {
        int n = words.size();
        vector<int> freq(26, 0);

        for(string word : words) {
            for(char c : word) {
                freq[c - 'a']++;
            }
        }

        for(int i = 0; i<26; i++) {
            if(freq[i]%n) return false;
        }

        return true;
    }
};