class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_sum = INT_MIN, curr_sum = 0;
        for(int num : nums) {
            curr_sum = max(curr_sum, 0) + num;
            max_sum = max(max_sum, curr_sum);
        }

        return max_sum;
    }
};