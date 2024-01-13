class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> freq(26, 0);
        for(int i = 0; i<s.size(); i++) {
            freq[s[i] - 'a']++;
            freq[t[i] - 'a']--;
        }

        int diff = 0;
        for(int i = 0; i<26; i++) {
            diff += abs(freq[i]);
        }

        return diff/2;
    }
};