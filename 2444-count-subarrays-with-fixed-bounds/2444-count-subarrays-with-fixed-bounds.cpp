class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int n = nums.size(), min_idx = -1, max_idx = -1, bad_idx = 0;
        long long ans = 0;

        for(int i = 0; i<n; i++) {
            if(nums[i] < minK || nums[i] > maxK) {
                bad_idx = i + 1;
            }

            if(nums[i] == minK) min_idx = i;
            if(nums[i] == maxK) max_idx = i;

            ans += max(0, min(min_idx, max_idx) - bad_idx + 1);
        }

        return ans;
    }
};