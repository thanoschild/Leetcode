class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> ans;
        int n = s.size();
        string str = "";

        for(int i = 0; i<n; i++) {
           str += s[i];
           if(str.size() == k) {
              ans.push_back(str);
              str = "";
           }
        }

        if(str.size() > 0) {
            while(str.size() < k) str += fill;
            ans.push_back(str);
        }

        return ans;
    }
};