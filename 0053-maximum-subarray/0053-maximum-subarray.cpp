class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = INT_MIN, sum = 0;
        for(int it : nums) {
            sum = max(0, sum) + it;
            ans = max(ans, sum);
        }

        return ans;
    }
};