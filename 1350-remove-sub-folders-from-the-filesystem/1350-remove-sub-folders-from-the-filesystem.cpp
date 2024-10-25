class Solution {
public:
    bool myCompare(const string &a, const string &b) {
        return a.size() < b.size();
    }

    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end(), [](const string &a, const string &b) {
            return a.size() < b.size();
        });
        unordered_set<string> st;

        for(string s : folder) {
            string curr = "";
            bool flag = true;
            for(char c : s) {
                if(c == '/' && curr != "") {
                    if(st.find(curr) != st.end()) {
                        flag = false;
                        continue;
                    }
                }
                curr += c;
            }
            if(st.find(curr) != st.end()) {
                flag = false;
                continue;
            }

            if(flag) st.insert(curr);
        }

        vector<string> ans;
        for(auto it : st) {
            ans.push_back(it);
        }

        return ans;
    }
};