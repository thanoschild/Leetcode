class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        int rem = 0, curr = 0, ans = n;

        for(auto it : nums) rem = (rem + it) % p;

        unordered_map<int, int> mp;
        mp[0] = -1;
        for(int i = 0; i<n; i++) {
            curr = (curr + nums[i]) % p;
            mp[curr] = i;
            int req = (curr - rem + p) % p;
            if(mp.find(req) != mp.end()) ans = min(ans, i - mp[req]);
        }

        return ans == n ? -1 : ans;
    }
};