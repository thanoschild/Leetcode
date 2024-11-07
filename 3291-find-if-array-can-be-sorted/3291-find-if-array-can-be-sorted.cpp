class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        int n = nums.size(), idx = 0;

        while(idx < n-1) {
            int a = __builtin_popcount(nums[idx]);
            int b = __builtin_popcount(nums[idx+1]);

            if(nums[idx] > nums[idx+1] && a == b) {
                swap(nums[idx], nums[idx+1]);
                idx = 0;
            } else if(nums[idx] <= nums[idx+1]) idx++;
            else if(nums[idx] > nums[idx+1] && a != b) return false;
        }

        for(int i = 1; i<n; i++) {
            if(nums[i-1] > nums[i]) return false;
        }

        return true;
    }
};