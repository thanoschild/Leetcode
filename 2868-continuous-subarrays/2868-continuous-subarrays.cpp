class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        map<int, int> freq;
        int left = 0, right = 0, n = nums.size();
        long long ans = 0;

        while(right < n) {
            freq[nums[right]]++;
            while(freq.rbegin()->first - freq.begin()->first > 2) {
                freq[nums[left]]--;
                if(freq[nums[left]] == 0) {
                    freq.erase(nums[left]);
                }
                left++;
            }

            ans += (right - left + 1);
            right++;
        }

        return ans;
    }
};