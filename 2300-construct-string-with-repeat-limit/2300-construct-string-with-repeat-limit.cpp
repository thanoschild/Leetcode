class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        int freq[26] = {0};
        for (char c : s)
            freq[c - 'a']++;
        string ans(s.size(), '_');
        int k = 0;
        set<int> st;
        for (int i = 25; i >= 0; i--) {
            int count = 0, curr = 0;
            while (count < freq[i] && st.size()) {
                ans[*st.begin()] = i + 'a';
                st.erase(st.begin());
                count++;
            }
            while (count < freq[i]) {
                if (curr == repeatLimit)
                    st.insert(k), k++, curr = 0;

                if (k > s.size())
                    break;

                ans[k] = i + 'a';
                curr++, k++, count++;
            }
        }
        for (int i = 0; i < ans.size(); i++) {
            if (ans[i] == '_') {
                ans.erase(ans.begin() + i, ans.end());
                break;
            }
        }
        return ans;
    }
};