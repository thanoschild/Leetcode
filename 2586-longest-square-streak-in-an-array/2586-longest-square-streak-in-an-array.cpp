class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        if(n == 0) return -1;
        unordered_map<int, int> dp;
        sort(nums.begin(), nums.end());

        for(auto it : nums) {
            int root = sqrt(it);
            if(root * root == it) {
                dp[it] = 1 + dp[root];
            } else {
                dp[it] = 1;
            }
            ans = max(dp[it], ans);
        }

        return ans < 2 ? -1 : ans;
    }
};