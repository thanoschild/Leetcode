class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> sum_arr;
        for(int i = 0; i<n; i++) {
            int sum = 0;
            for(int j = i; j<n; j++) {
                sum += nums[j];
                sum_arr.push_back(sum);
            }
        }

        sort(sum_arr.begin(), sum_arr.end());
        int ans = 0, mod = 1e9 + 7;
        for(int i = left-1; i<right; i++) {
            ans = (ans + sum_arr[i])%mod;
        }

        return ans;
    }
};