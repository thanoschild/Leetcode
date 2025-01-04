class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<int> maxIdx(26, INT_MIN), minIdx(26, INT_MAX);
        for(int i = 0; i<s.size(); i++) {
            maxIdx[s[i] - 'a'] = max(maxIdx[s[i] - 'a'], i);
            minIdx[s[i] - 'a'] = min(minIdx[s[i] - 'a'], i);
        }

        int ans = 0;
        for(int i = 0; i<26; i++) {
            if(maxIdx[i] == INT_MIN | minIdx[i] == INT_MAX) continue;
            unordered_set<char> st;
            for(int j = minIdx[i] + 1; j<maxIdx[i]; j++) {
                st.insert(s[j]);
            }
            ans += st.size();
        }

        return ans;
    }
};