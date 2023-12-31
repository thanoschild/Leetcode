class Solution {
public:
    bool hasTrailingZeros(vector<int>& nums) {
        int count = 0;
        for(int n : nums) {
            if(n % 2 == 0) count++;
        }
        
        return count >= 2;
    }
};