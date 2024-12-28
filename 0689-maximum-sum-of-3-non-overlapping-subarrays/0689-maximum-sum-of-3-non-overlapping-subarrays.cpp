class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        const int n = nums.size();
        vector<int> prefix(n - k + 1, 0);
        int sum = 0;

        for(int i = 0; i<k; i++) sum += nums[i];
        prefix[0] = sum;

        for(int i = k; i<n; i++) {
            sum += nums[i] - nums[i-k];
            prefix[i - k + 1] = sum;
        }
        
        int m = prefix.size();
        vector<int> left(m, 0);
        int maxIdx = 0;
        for(int i = 0; i<m; i++) {
            if(prefix[i] > prefix[maxIdx]) maxIdx = i;
            left[i] = maxIdx;
        }

        vector<int> right(m, 0);
        maxIdx = m - 1;
        for(int i = m - 1; i>=0; i--) {
            if(prefix[i] >= prefix[maxIdx]) maxIdx = i;
            right[i] = maxIdx;
        }

        vector<int> ans(3, 0);
        int maxSum = 0;
        for(int i = k; i<m-k; i++) {
            int l = left[i-k];
            int r = right[i + k];
            int total = prefix[l] + prefix[i] + prefix[r];
            if(total > maxSum) {
                maxSum = total;
                ans = {l, i, r};
            }
        }

        return ans;
    }
};