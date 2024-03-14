class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int, int> mp;
        mp[0] = 1;
        int sum = 0, ans = 0;
        for(int it : nums) {
            sum += it;
            ans += mp[sum - goal];
            mp[sum]++;
        }

        return ans;
    }
};