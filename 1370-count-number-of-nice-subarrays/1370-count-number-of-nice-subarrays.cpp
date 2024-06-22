class Solution {
public:
    int atMostK(vector<int> &nums, int k) {
        int ans = 0, count = 0;
        for(int i = 0, j = 0; i<nums.size(); i++) {
            count += nums[i]%2;
            while(count > k) {
                count -= nums[j++] % 2;
            }
            ans += (i - j);
        }
        return ans;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = atMostK(nums, k);
        int m = atMostK(nums, k - 1);
        return n - m;
    }
};