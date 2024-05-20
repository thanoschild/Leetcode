class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int ans = 0;
        for(int i = 1; i<(1 << nums.size()); i++) {
            int total = 0;
            for(int j = 0; j<nums.size(); j++) {
                if(i & (1 << j)) {
                    total ^= nums[j];
                }
            }
            ans += total;
        }

        return ans;
    }
};