class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        for(int i = 0; i<n-2; i++) {
            int a = (nums[i] + nums[i + 2]) * 2;
            int b = nums[i + 1];
            if(a == b) ans++;
        }

        return ans;
    }
};