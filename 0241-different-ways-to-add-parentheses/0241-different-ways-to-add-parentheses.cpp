class Solution {
public:
    unordered_map<string, vector<int>> dp;

    vector<int> backtrack(int left, int right, string exp) {
        string key = to_string(left) + "," + to_string(right);
        if(dp.find(key) != dp.end()) {
            return dp[key];
        } 
        vector<int> ans;

        for(int i = left; i<=right; i++) {
            char op = exp[i];
            if(op == '+' || op == '-' || op == '*') {
                vector<int> nums1 = backtrack(left, i - 1, exp);
                vector<int> nums2 = backtrack(i + 1, right, exp);

                for(int n1 : nums1) {
                    for(int n2 : nums2) {
                        if(op == '+') {
                            ans.push_back(n1 + n2);
                        }
                        else if(op == '-') {
                            ans.push_back(n1 - n2);
                        }
                        else {
                            ans.push_back(n1 * n2);
                        }
                    }
                }
            }
        }

        if(ans.empty()) ans.push_back(stoi(exp.substr(left, right - left + 1)));

        dp[key] = ans;
        return ans;
    }

    vector<int> diffWaysToCompute(string expression) {
        return backtrack(0, expression.size() - 1, expression);
    }
};