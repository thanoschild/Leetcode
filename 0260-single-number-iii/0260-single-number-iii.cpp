class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n = nums.size();
        long long _xor = 0;
        for(int i = 0; i<n; i++) _xor ^= nums[i];

        long long rightBit = _xor & (-_xor);
        int x = 0, y = 0;

        for(int i = 0; i<n; i++) {
            if((rightBit & nums[i]) == 0) x ^= nums[i];
            else y ^= nums[i];
        }

        return {x, y};
    }
};