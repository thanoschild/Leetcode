class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int i = 0, ans = 0;
        for(i = 0; i<nums.size(); i++) ans = ans ^ i ^ nums[i];
        return ans ^ i;
    }
};