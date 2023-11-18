class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int freq = 0, left = 0;
        long long sum = 0;
        sort(nums.begin(), nums.end());
        for(int right = 0; right<nums.size(); right++) {
            sum += nums[right];
            while((long)sum + k < (long) nums[right] * (right - left + 1)) {
               sum -= nums[left], left++;
            }
            freq = max(freq, (right - left + 1));
        }
        return freq;
    }
};