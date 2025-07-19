class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        unordered_set<string> st;
        sort(folder.begin(), folder.end(),
             [](const string& a, const string& b) {
                 return a.size() < b.size();
             });

        for (string s : folder) {
            string temp = "", curr = "";
            bool flag = false;
            for (int i = 0; i < s.size(); i++) {
                char c = s[i];
                if (c == '/') {
                    temp += curr;
                    if (st.find(temp) != st.end()) {
                        flag = true;
                        break;
                    }

                    temp += '/';
                    curr = "";
                } else {
                    curr += c;
                }
            }
            if(curr.size() != 0) temp += curr;
            if (st.find(temp) != st.end()) {
                flag = true;
                break;
            }
            if (!flag) st.insert(s);
        }

        vector<string> ans;
        for (auto s : st)
            ans.push_back(s);

        return ans;
    }
};