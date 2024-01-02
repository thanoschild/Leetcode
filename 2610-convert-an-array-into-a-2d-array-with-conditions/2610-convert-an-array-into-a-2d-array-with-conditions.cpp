class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        int max_freq = 0;
        int n = nums.size();
        vector<int> freq(n+1, 0);

        for(auto it : nums) {
            freq[it]++;
            max_freq = max(max_freq, freq[it]);
        }

        vector<vector<int>> ans(max_freq);
        for(int i = 0; i<freq.size(); i++) {
            for(int j = 0; j<freq[i]; j++) {
                ans[j].push_back(i);
            }
        }

        return ans;
    }
};