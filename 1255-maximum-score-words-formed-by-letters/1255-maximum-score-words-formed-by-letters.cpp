class Solution {
public:
    int solve(vector<string> &words, vector<int> &count, vector<int> &score, int idx) {
        int ans = 0;
        for(int i = idx; i<words.size(); i++) {
            int curr = 0;
            bool flag = true;
            for(char c : words[i]) {
                count[c - 'a']--;
                curr += score[c - 'a'];
                if(count[c - 'a'] < 0) flag = false; 
            }
            if(flag) {
                curr += solve(words, count, score, i+1);
                ans = max(ans, curr);
            }
            for(char c : words[i]) {
                count[c - 'a']++;
                curr = 0;
            }
        }
        return ans;
    }

    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        int n = words.size(), m = letters.size(), p = score.size();
        if(n == 0 || m == 0 || p == 0) return 0;
        vector<int> count(p, 0);
        for(char c : letters) {
            count[c - 'a']++;
        }
        
        return solve(words, count, score, 0);
    }
};