class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> prefix(n, 0);

        for(int i = 1; i<n; i++) {
            prefix[i] = prefix[i-1];
            if((nums[i-1] % 2 == 0 && nums[i] % 2 == 0) || (nums[i-1] % 2 == 1 && nums[i] % 2 == 1)) {
                prefix[i]++;
            }
        }

        vector<bool> ans;
        for(auto it : queries) {
            int count = prefix[it[1]] - prefix[it[0]];
            ans.push_back(count == 0);
        }

        return ans;
    }
};