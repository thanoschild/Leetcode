class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
        vector<long long> prefix;
        long long sum = 0;
        for(int num : nums) {
            sum += num;
            prefix.push_back(sum);
        }

        int ans = 0;
        sum = 0;
        for(int i = n - 1; i>0; i--) {
            sum += nums[i];
            long long left = i > 0 ? prefix[i-1] : 0;
            if(left >= sum) ans++;
        }

        return ans;
    }
};