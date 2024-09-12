class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        set<char> st(allowed.begin(), allowed.end());
        int count = 0;
        bool flag = true;

        for(string s : words) {
            flag = true;
            for(char c : s) {
                if(st.find(c) == st.end()) {
                    flag = false;
                    break;
                }
            }

            if(flag) count++;
        }

        return count;
    }
};