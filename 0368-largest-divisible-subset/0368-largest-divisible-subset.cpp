class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size(), maxVal = -1, start = -1;
        if(n == 1) return nums;
        
        vector<int> dp(n, 1);
        vector<int> parent(n);

        sort(nums.begin(), nums.end());
        for(int i = 1; i<n; i++) {
            for(int j = 0; j<i; j++) {
                if(nums[i] % nums[j] == 0) {
                    if(dp[i] < dp[j] + 1) {
                        dp[i] = dp[j] + 1;
                        parent[i] = j;
                    }
                }
            }

            if(dp[i] > maxVal) {
                maxVal = dp[i];
                start = i;
            }
        }

        vector<int> ans;
        for(int i = 0; i<maxVal; i++) {
            ans.push_back(nums[start]);
            start = parent[start];
        }

        return ans;
    }
};