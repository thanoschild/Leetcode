class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        int len = n + m;
        int sum = accumulate(rolls.begin(), rolls.end(), 0);
        vector<int> ans;
        int remainingSum = mean * len - sum;
        
        int currVal = remainingSum/n;
        int rem = remainingSum % n;
        if (remainingSum < n || remainingSum > 6 * n) return ans;

        ans.resize(n);
        for(int i = 0; i<n; i++) {
            if(rem > 0) {
                ans[i] = currVal + 1;
                rem--;
            }
            else ans[i] = currVal;
        }

        return ans;
    }
};