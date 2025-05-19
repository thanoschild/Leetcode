class Solution {
    public String triangleType(int[] nums) {
        int LongSide = LongSide = Math.max(nums[0], Math.max(nums[1], nums[2]));
        int sum = nums[0] + nums[1] + nums[2];

        int twoSide = sum - LongSide;
        if(LongSide >= twoSide) return "none";

        if(nums[0] == nums[1] && nums[1] == nums[2]) return "equilateral";

        if(nums[0] == nums[1] || nums[1] == nums[2] || nums[0] == nums[2]) return "isosceles";

        return "scalene";
    }
}