class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int ans1 = INT_MIN, ans2 = INT_MIN, n = nums.size();
        sort(nums.begin(), nums.end());
        for(int i = 0; i<n/2; i++) {
            ans1 = max(ans1, nums[i] + nums[n - i - 1]);
            ans2 = max(ans2, nums[i] + nums[n/2 + i]);
        }
        return min(ans1, ans2);
    }
};