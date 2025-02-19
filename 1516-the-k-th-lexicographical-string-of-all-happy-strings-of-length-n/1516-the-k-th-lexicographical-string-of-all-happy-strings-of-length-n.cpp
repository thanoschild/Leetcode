class Solution {
public:
    void solve(int n, vector<string> &happy, string curr) {
        if(curr.size() == n) {
            happy.push_back(curr);
            return;
        }

        for(char c = 'a'; c<'d'; c++) {
            if(curr.empty() || curr.back() != c) {
                solve(n, happy, curr + c);
            }
        }
    }

    string getHappyString(int n, int k) {
        vector<string> happy;
        string curr = "";
        solve(n, happy, curr);
        if(k > happy.size()) return "";
        return happy[k-1];
    }
};