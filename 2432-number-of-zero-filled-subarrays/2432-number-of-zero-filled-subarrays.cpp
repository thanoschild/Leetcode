class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans = 0, count = 0;
        for(int n : nums) {
            if(n == 0) ans += (++count);
            else count = 0;
        }

        return ans;
    }
};