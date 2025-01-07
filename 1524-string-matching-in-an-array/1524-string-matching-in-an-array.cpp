class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        int n = words.size();
        sort(words.begin(), words.end(), [&](const string &a, const string &b) {
            return a.size() > b.size();
        });

        unordered_set<string> st;
        for(int i = 0; i<n; i++) {
            for(int j = i + 1; j<n; j++) {
                if(words[i].find(words[j]) != string::npos) {
                   st.insert(words[j]);
                }
            }
        }

        vector<string> ans;
        for(auto it : st) ans.push_back(it);
        return ans;
    }
};