class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int ans = 0, curr = 0, i = 0, j = 0, n = nums.size();

        while(i < n && j < n) {
            if((curr & nums[i]) == 0) {
                ans = max(ans, i - j + 1);
                curr |= nums[i];
                i++;
            } else {
                curr ^= nums[j];
                j++;
            }
        }

        return ans;
    }
};