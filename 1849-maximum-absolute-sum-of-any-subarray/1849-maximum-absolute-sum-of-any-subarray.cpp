class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int sum = 0, minSum = 0, maxSum = 0;
        for(auto it : nums) {
            sum += it;
            minSum = min(sum, minSum);
            maxSum = max(sum, maxSum);
        }

        return maxSum - minSum;
    }
};