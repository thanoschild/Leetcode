class Solution {
public:
  
    string findDifferentBinaryString(vector<string>& nums) {
        string ans = "";
        for(int i = 0; i<nums.size(); i++) {
            char curr = nums[i][i];
            char opp = (curr == '0') ? '1' : '0';
            ans += opp;
        }

        return ans;
    }
};