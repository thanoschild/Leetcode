class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        vector<int> ans(n);
        int left = 0, right = n - 1;

        for(int i = 0, j = n - 1; i<n; i++, j--) {
            if(nums[i] < pivot) {
                ans[left] = nums[i];
                left++;
            }

            if(nums[j] > pivot) {
                ans[right] = nums[j];
                right--;
            }
        }

        while(left <= right) {
            ans[left] = pivot;
            left++;
        }

        return ans;
    }
};