class Solution {
public:
    vector<int> getFreq(string word) {
        vector<int> count(26, 0);
        for(char c : word) {
            count[c - 'a']++;
        }
        return count;
    }
    
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string> ans;
        vector<int> freq(26, 0), currFreq(26, 0);

        for(string word : words2) {
            currFreq = getFreq(word);
            for(int i = 0; i<26; i++) {
                freq[i] = max(freq[i], currFreq[i]);
            }
        }

        for(string word : words1) {
            currFreq = getFreq(word);
            bool flag = true;
            for(int i = 0; i<26; i++) {
                if(currFreq[i] < freq[i]) flag = false;
            }
            if(flag) ans.push_back(word);
        }

        return ans;
    }
};