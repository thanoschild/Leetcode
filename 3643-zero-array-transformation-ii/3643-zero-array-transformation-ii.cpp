class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size(), m = queries.size(), sum = 0, ans = 0;
        vector<int> freq(n+1);

        for(int i = 0; i<n; i++) {
            while(sum + freq[i] < nums[i]) {
                if(ans >= m) return -1;
                int l = queries[ans][0], r = queries[ans][1], val = queries[ans][2];
                ans++;
                if(r < i) continue;
                freq[max(l, i)] += val;
                freq[r+1] -= val;
            }
            sum += freq[i];
        }
        return ans;
    }
};

/*

[2, 0, 2]
[0, 0, 2, 2]
[0, -2, 0, ]
*/