class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        vector<long long> presum;
        long long sum = 0;
        sort(nums.begin(), nums.end());
        for(auto it : nums) {
            presum.push_back(sum);
            sum += it;
        }

        for(int i = nums.size() - 1; i>=2; i--) {
            if(nums[i] < presum[i]) {
                return presum[i] + (long long) nums[i];
            }
        }

        return -1;
    }
};