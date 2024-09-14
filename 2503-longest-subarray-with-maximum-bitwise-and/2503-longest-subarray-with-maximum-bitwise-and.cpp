class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int mx = -1, count = 0, ans = 0;
        for(auto it : nums) mx = max(mx, it);

        for(auto it : nums) {
            if(mx == it) count++;
            else count = 0;
            ans = max(ans, count);
        }

        return ans;
    }
};