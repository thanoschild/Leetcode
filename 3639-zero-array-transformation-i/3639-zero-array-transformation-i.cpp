class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size(), m = queries.size();
        vector<int> freq(n+1);

        for(int i = 0; i<m; i++) {
            int l = queries[i][0], r = queries[i][1];
            freq[l] += 1;
            freq[r+1] += -1;
        }
        for(int i = 1; i<=n; i++) {
            freq[i] += freq[i-1];
        }

        for(int i = 0; i<n; i++) {
            if(freq[i] < nums[i]) return false;
        }

        return true;
    }
};