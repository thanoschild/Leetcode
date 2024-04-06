class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        bool flag = true;

        for(int i = n - 2; i>=0; i--) {
            if(nums[i] < nums[i+1]) {
                flag = false;
                sort(nums.begin() + i + 1, nums.end());
                int k = i + 1;
                while(nums[i] >= nums[k]) k++;
                swap(nums[i], nums[k]);
                break;
            }
        }

        if(flag) sort(nums.begin(), nums.end());
    }
};