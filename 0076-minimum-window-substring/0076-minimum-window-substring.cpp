class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size(), m = t.size();
        if(n == 0 || m == 0 || m > n) return "";
        vector<int> v(256, 0);
        for(char c : t) {
            v[c]++;
        }

        int start = 0, end = 0, len = INT_MAX, ans = 0, count = 0;
        while(end < n) {
            if(v[s[end]] > 0) count++;
            v[s[end]]--;
            while(count == m) {
                if(len > end - start + 1) {
                    len = end - start + 1;
                    ans = start;
                }
                v[s[start]]++;
                if(v[s[start]] > 0) count--;
                start++;
            }
            end++;
        }

        return len == INT_MAX ? "" : s.substr(ans, len);
    }
};