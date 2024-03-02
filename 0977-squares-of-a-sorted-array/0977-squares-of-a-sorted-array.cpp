class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        int n = nums.size();
        int left = 0, right = n - 1;
        vector<int> ans(n);

        for(int i = n - 1; i>=0; i--) {
            if(abs(nums[left]) >= abs(nums[right])) {
                ans[i] = pow(nums[left], 2);
                left++;
            }
            else {
                ans[i] = pow(nums[right], 2);
                right--;
            }
        }

        return ans;
    }
};