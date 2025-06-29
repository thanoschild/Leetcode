class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int left = 0, right = nums.size() - 1, mod = 1e9 + 7, ans = 0;

        vector<int> power(nums.size(), 1);
        for (int i = 1; i < nums.size(); ++i) {
            power[i] = (power[i - 1] * 2) % mod;
        }

        while(left <= right) {
            if(nums[left] + nums[right] > target) {
                right--;
            } else {
                ans = (ans + power[right - left]) % mod;
                left++;
            }
        }

        return ans;
    }
};