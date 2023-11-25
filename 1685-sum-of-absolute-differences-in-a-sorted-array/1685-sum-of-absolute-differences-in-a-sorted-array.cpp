class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int right = accumulate(nums.begin(), nums.end(), 0);
        int left = 0, n = nums.size();
        vector<int> ans;
        
        for(int i = 0; i<n; i++) {
            int val = nums[i];
            right -= val;
            ans.push_back(val*i - left + right - val*(n - i - 1));
            left += val;
        }
        
        return ans;
    }
};