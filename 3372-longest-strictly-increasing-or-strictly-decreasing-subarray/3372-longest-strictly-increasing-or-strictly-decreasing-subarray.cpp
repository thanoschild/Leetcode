class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size(), asc = 1, desc = 1, ans = 1;

        for(int i = 1; i<n; i++) {
            if(nums[i] > nums[i-1]) {
                desc++;
                asc = 1;
            } else if(nums[i] < nums[i-1]) {
                asc++;
                desc = 1;
            } else {
                desc = 1;
                asc = 1;
            }
            ans = max({ans, asc, desc});
        }

        return ans;
    }
};