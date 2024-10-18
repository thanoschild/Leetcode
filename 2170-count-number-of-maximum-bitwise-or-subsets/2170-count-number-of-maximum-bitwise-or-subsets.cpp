class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int max = 0, dp[1 << 17] = {1};
        for(int n : nums) {
            for(int i = max; i >=0; i--) {
                dp[i | n] += dp[i];
            }
            max |= n;
        }

        return dp[max];
    }
};