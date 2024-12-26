class Solution {
public:
    unordered_map<int, unordered_map<int,int>> mp;
    int find_target(vector<int> &nums, int sum, int target, int idx){
        if(idx == nums.size()){
            if(sum == target) return 1;
            return 0;
        }
        
        if(mp.count(idx) && mp[idx].count(sum)){
            return mp[idx][sum];
        }
        
        int ans = 0;
        ans += find_target(nums, sum - nums[idx], target, idx + 1);
        ans += find_target(nums, sum + nums[idx], target, idx + 1);
        
        return mp[idx][sum] = ans;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return find_target(nums, 0, target, 0);
    }
};