class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        int n = nums.size();
        vector<int> delta(n, 0);
        for(int i = 0; i<n; i++) {
            delta[i] = (nums[i] ^ k) - nums[i];
        }

        long long ans = 0;
        for(int n : nums) ans += n;

        sort(delta.begin(), delta.end(), greater<int>());
        for(int i = 0; i<n; i+=2) {
            if(i == n - 1) break;
            int curr_delta = delta[i] + delta[i + 1];
            if(curr_delta <= 0) break;
            ans += curr_delta;
        }

        return ans;
    }
};