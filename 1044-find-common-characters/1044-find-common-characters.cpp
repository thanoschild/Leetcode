class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int> seen(26, INT_MAX);
        for(string s : words) {
            vector<int> count(26, 0);
            for(char c : s) {
                count[c - 'a']++;
            }
            for(int i = 0; i<26; i++) {
                seen[i] = min(seen[i], count[i]);
            }
        }

        vector<string> ans;
        for(int i = 0; i<26; i++) {
            for(int j = 0; j<seen[i]; j++) {
                ans.push_back(string(1, 'a' + i));
            }
        }

        return ans;
    }
};