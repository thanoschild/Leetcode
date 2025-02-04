class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int n = nums.size(), sum = nums[0], ans = nums[0];

        for(int i = 1; i<n; i++) {
            if(nums[i-1] < nums[i]) sum += nums[i];
            else sum = nums[i];
            ans = max(ans, sum);
        }

        return ans;
    }
};