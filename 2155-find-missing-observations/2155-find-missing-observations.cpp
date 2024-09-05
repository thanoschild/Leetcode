class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int sum = accumulate(rolls.begin(), rolls.end(), 0);
        int m = rolls.size();
        int missingSum = mean * (n + m) - sum;
        if(missingSum < n || missingSum > n * 6) return {};

        int val = missingSum / n, rem = missingSum % n;
        vector<int> ans(n, val);
        for(int i = 0; i<rem; i++) ans[i]++;

        return ans;
    }
};