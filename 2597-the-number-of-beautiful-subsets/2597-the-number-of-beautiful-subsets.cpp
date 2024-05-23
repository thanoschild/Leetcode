class Solution {
public:
    void dfs(vector<int> &nums, int idx, unordered_map<int ,int> &mp, int &ans, int k) {
        if(idx == nums.size()) {
            ans++;
            return;
        }
        if(!mp[nums[idx] - k] && !mp[nums[idx] + k]) {
            mp[nums[idx]]++;
            dfs(nums, idx + 1, mp, ans, k);
            mp[nums[idx]]--;
        }
        dfs(nums, idx + 1, mp, ans, k);
    }

    int beautifulSubsets(vector<int>& nums, int k) {
        int ans = 0;
        unordered_map<int, int> mp;
        dfs(nums, 0, mp, ans, k);
        return ans - 1;
    }
};