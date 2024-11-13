class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        long ans = 0;
        sort(nums.begin(), nums.end());

        for(int i = 0; i<n - 1; i++) {
            int x = lower - nums[i];
            int y = upper - nums[i];
            auto a = lower_bound(nums.begin() + i + 1, nums.end(), x);
            auto b = upper_bound(nums.begin() + i + 1, nums.end(), y);
            ans += (b - a);
        }

        return ans;
    }
};