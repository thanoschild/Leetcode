class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        unordered_map<string, function<long (long, long) >> mp = {
            {"+", [] (long a, long b) {return a + b;}},
            {"-", [] (long a, long b) {return a - b;}},
            {"*", [] (long a, long b) {return a * b;}},
            {"/", [] (long a, long b) {return a / b;}}
        };

        stack<long> st;
        for(string s : tokens) {
            if(!mp.count(s)) {
                st.push((long)stoi(s));
            }
            else {
                long a = st.top();
                st.pop();
                long b = st.top();
                st.pop();
                st.push(mp[s] (b, a));
            }
        }

        return st.top();
    }
};