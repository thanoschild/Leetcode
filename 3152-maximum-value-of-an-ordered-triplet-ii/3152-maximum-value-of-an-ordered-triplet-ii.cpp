#define ll long long

class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        ll ans = 0, maxDiff = -1, maxVal = -1;

        for(ll it : nums) {
           ans = max(ans, maxDiff * it);
           maxVal = max(maxVal, it);
           maxDiff = max(maxDiff, maxVal - it);
        }

        return ans;
    }
};