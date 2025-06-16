class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n = nums.size(), minVal = nums[0], ans = -1;
        for(int it : nums) {
           ans = max(ans, it - minVal);
           minVal = min(minVal, it);
        }

        return ans == 0 ? -1 : ans;
    }
};