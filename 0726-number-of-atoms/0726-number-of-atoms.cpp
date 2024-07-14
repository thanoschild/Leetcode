class Solution {
public:
    string countOfAtoms(string s) {
        stack<unordered_map<string,int>> st;
        unordered_map<string,int> m;
        int i = 0, n = s.size();
        while(i < n) {
            if(s[i] == '(') {
                st.push(m);
                m = {};
                i++;
            }
            else if(s[i] == ')') {
                int val = 0;
                i++;
                while(i < s.size() && s[i] >= '0' && s[i] <= '9') {
                    val = val * 10 + (s[i++] - '0');
                }
                if(!val) val = 1;
                unordered_map<string,int> temp = m;
                m = st.top();
                st.pop();
                for(auto x : temp) {
                    m[x.first] += temp[x.first]*val;
                }
            }
            else {
                string tmpp = s.substr(i++, 1);
                while(i < s.size() && islower(s[i])) tmpp += s[i++];
                int val = 0;
                while(i < s.size() && s[i] >= '0' && s[i] <= '9') {
                    val = val * 10 + (s[i++] - '0');
                }
                if(!val) val = 1;
                m[tmpp] += val;
            }
        }

        vector<pair<string,int>> v;
        for(auto x : m) {
            v.push_back({x.first, x.second});
        }
        sort(v.begin(), v.end());
        string ans = "";
        for(pair<string, int> &p : v) {
            ans += p.first + (p.second > 1 ? to_string(p.second) : ""); 
        }

        return ans;
    }
};