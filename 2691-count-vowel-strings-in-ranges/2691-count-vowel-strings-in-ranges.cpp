class Solution {
public:
    bool checkVowel(char c) {
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') return true;
        return false;
    }

    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size(), count = 0;
        vector<int> prefix;
        for(string word : words) {
            if(checkVowel(word[0]) && checkVowel(word[word.size() - 1])) count++;
            prefix.push_back(count);
        }

        vector<int> ans;
        for(auto query : queries) {
            int start = query[0], end = query[1];
            int val = 0;
            if(start > 0) val = prefix[end] - prefix[start-1];
            else val = prefix[end];
            ans.push_back(val);
        }

        return ans;
    }
};