class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size(), ans = 0;
        unordered_map<int, int> mp;
        
        for(int i = 0, j = 0; j<n; j++) {
            mp[nums[j]]++;
            if(mp[nums[j]] > k) {
                while(nums[i] != nums[j]) {
                    mp[nums[i]]--;
                    i++;
                }
                mp[nums[i]]--;
                i++;
            }
            ans = max(ans, j - i + 1);
        }

        return ans;
    }
};