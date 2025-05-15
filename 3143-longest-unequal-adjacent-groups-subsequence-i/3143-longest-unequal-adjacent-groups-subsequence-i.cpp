class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        vector<string> ans;
        int n = groups.size(), last = -1;
        for(int i = 0; i<n; i++) {
            if(groups[i] != last) {
                ans.push_back(words[i]);
                last = groups[i];
            }
        }

        return ans;
    }
};