class Solution {
public:
    string triangleType(vector<int>& nums) {
        int LongSide = 0, sum = 0;
        for(int it : nums) {
            LongSide = max(LongSide, it);
            sum += it;
        }

        int twoSide = sum - LongSide;
        if(LongSide >= twoSide) return "none";

        if(nums[0] == nums[1] && nums[1] == nums[2]) return "equilateral";

        if(nums[0] == nums[1] || nums[1] == nums[2] || nums[0] == nums[2]) return "isosceles";

        return "scalene";
    }
};