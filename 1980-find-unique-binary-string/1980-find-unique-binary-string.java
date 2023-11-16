class Solution {
    public String findDifferentBinaryString(String[] nums) {
        StringBuilder ans = new StringBuilder();
        for(int i = 0; i<nums.length; i++) {
            char curr = nums[i].charAt(i);
            char opp = (curr == '0') ? '1' : '0';
            ans.append(opp);
        }
        
        return ans.toString();
    }
}