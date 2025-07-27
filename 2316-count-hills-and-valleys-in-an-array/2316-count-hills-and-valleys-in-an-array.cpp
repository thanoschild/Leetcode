class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int ans = 0;
        for(int i = 1, j=0; i<nums.size() - 1; i++) {
            if(nums[j] < nums[i] && nums[i] > nums[i+1] || (nums[j] > nums[i] && nums[i] < nums[i+1])) {
                ans++;
                j = i;
            }
        }

        return ans;
    }
};