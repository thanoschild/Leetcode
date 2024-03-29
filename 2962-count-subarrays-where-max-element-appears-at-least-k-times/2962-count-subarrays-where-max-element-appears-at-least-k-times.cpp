class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n = nums.size(), count = 0;
        int max_ele = *max_element(nums.begin(), nums.end());
        long long ans = 0;

        for(int i = 0, j = 0; j<n; j++) {
            if(nums[j] == max_ele) count++;
            while(count >= k) {
                ans += (n - j);
                if(nums[i] == max_ele) count--;
                i++;
            }
        }

        return ans;
    }
};