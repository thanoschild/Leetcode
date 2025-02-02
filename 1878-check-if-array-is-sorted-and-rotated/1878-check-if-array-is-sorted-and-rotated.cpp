class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        if(n <= 2) return true;
        int count = 0;
        for(int i = 0; i<n-1; i++) {
            if(nums[i] > nums[i+1]) count++;
        }
        if(nums[n - 1] > nums[0]) count++;

        return count <= 1 ? true : false;
    }
};