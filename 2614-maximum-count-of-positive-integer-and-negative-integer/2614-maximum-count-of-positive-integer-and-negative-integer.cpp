class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int pos = 0, zero = 0, neg = 0;
        for(int n : nums) {
            if(n == 0) zero++;
            else if(n > 0) pos++;
            else neg++;
        }

        return max(pos, neg);
    }
};