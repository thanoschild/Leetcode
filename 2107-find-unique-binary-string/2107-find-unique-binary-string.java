class Solution {
    public String findDifferentBinaryString(String[] nums) {
        String ans = "";
        for(int i = 0; i<nums.length; i++) {
            if(nums[i].charAt(i) == '0') ans += '1';
            else ans += '0';
        }

        return ans;
    }
}