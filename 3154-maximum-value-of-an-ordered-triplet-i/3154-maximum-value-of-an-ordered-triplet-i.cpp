class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long currMax = -1, ans = 0, maxDiff = 0;
        for(long long it : nums) {
            ans = max(ans, maxDiff * it);
            currMax = max(currMax, it);
            maxDiff = max(maxDiff, currMax - it);
        }

        return ans;
    }
};