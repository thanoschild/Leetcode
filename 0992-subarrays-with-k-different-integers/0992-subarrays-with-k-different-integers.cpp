class Solution {
public:
    int findKMostSubarrays(vector<int>& nums, int k) {
        int n = nums.size(), count = 0;
        unordered_map<int, int> mp;

        for(int i = 0, j = 0; j<n; j++) {
            mp[nums[j]]++;
            while(mp.size() > k) {
                mp[nums[i]]--;
                if(mp[nums[i]] == 0) mp.erase(nums[i]);
                i++;
            }
            count += (j - i + 1);
        }

        return count;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int ans1 = findKMostSubarrays(nums, k - 1);
        int ans2 = findKMostSubarrays(nums, k);
        return ans2 - ans1;
    }
};