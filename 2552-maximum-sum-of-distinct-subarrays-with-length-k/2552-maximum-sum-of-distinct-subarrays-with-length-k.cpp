class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> mp;
        long long ans = 0, sum = 0;
        for(int i = 0; i<n; i++){
            sum += nums[i];
            mp[nums[i]]++;
            if(i >= k - 1){
                if(mp.size() == k){
                    ans = max(ans, sum);
                }
                sum -= nums[i - k + 1];
                if(--mp[nums[i - k + 1]] == 0){
                    mp.erase(nums[i-k+1]);
                }
            }
        }
        
        return ans;
    }
};