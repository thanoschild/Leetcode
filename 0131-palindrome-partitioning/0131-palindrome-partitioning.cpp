class Solution {
public:
    bool check(string s, int i, int j) {
        while(i < j) {
            if(s[i++] != s[j--]) return false;
        }
        return true;
    }

    void solve(string s, int idx, vector<string> &curr, vector<vector<string>> &ans) {
        int n = s.size();
        if(idx == n) {
            ans.push_back(curr);
            return;
        }

        for(int i = idx; i<n; i++) {
            if(check(s, idx, i)) {
                curr.push_back(s.substr(idx, i - idx + 1));
                solve(s, i + 1, curr, ans);
                curr.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        if(s.size() == 0) return ans;
        vector<string> curr;
        solve(s, 0, curr, ans);
        return ans;
    }
};