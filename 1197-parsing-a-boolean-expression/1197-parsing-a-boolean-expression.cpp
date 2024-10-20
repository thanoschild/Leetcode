class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> st;

        for(char c : expression) {
            if(c == ',' || c == '(') continue;
            if(c == 't' || c == 'f' || c == '!' || c == '&' || c == '|') st.push(c);
            else if(c == ')') {
                bool hasTrue = false, hasFalse = false;
                while(st.top() != '!' && st.top() != '&' && st.top() != '|') {
                    char t = st.top();
                    st.pop();
                    if(t == 't') hasTrue = true;
                    if(t == 'f') hasFalse = true;
                }

                char t = st.top();
                st.pop();
                if(t == '!') st.push(hasTrue ? 'f' : 't');
                else if(t == '&') st.push(hasFalse ? 'f' : 't');
                else st.push(hasTrue ? 't' : 'f');
            }
        }

        return st.top() == 't';
    }
};