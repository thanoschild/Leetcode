class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        unordered_set<string> st;
        sort(folder.begin(), folder.end(),
             [](const string& a, const string& b) {
                 return a.size() < b.size();
             });

        for (string s : folder) {
            string temp = "";
            bool flag = false;
            for (int i = 0; i < s.size(); i++) {
                if(s[i] == '/' && temp.size() > 0) {
                   if(st.find(temp) != st.end()) {
                        flag = true;
                        break;
                    }
                } 
                temp += s[i];
            }
            
            if (st.find(temp) != st.end()) {
                flag = true;
                continue;
            }

            if (!flag) st.insert(s);
        }

        vector<string> ans;
        for (auto s : st)
            ans.push_back(s);

        return ans;
    }
};