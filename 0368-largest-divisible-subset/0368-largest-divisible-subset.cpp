class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums;
        vector<int> dp(n, + 1);
        vector<int> parent(n);

        int source = 0, mx = 1;
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
            if(dp[i] > mx) {
                mx = dp[i];
                source = i;
            }
        }

        vector<int> ans;
        for(int i = 0; i<mx; i++) {
            ans.push_back(nums[source]);
            source = parent[source];
        }

        return ans;
    }
};