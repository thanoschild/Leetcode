class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<int> minIdx(26, INT_MAX), maxIdx(26, INT_MIN);
        int n = s.size();
        int ans = 0;
        
        for(int i = 0; i<n; i++) {
            minIdx[s[i] - 'a'] = min(minIdx[s[i] - 'a'], i);
            maxIdx[s[i] - 'a'] = max(maxIdx[s[i] - 'a'], i);
        }
        
        for(int i = 0; i<26; i++) {
            if(minIdx[i] == INT_MAX || maxIdx[i] == INT_MIN) continue;
            
            unordered_set<char> st;
            for(int j = minIdx[i] + 1; j<maxIdx[i]; j++) {
                st.insert(s[j]);
            }
            ans += st.size();
        }
        
        return ans;
    }
};