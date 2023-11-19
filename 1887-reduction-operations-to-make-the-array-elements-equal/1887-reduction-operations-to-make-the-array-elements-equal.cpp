class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        int count = 0, prev = 0;
        for(int i = 1; i<n; i++) {
            if(nums[i] == nums[i-1]) {
                if(prev == 0) continue;
                else {
                    count += prev;
                }
            }
            else{
                prev += 1;
                count += prev;
            }
        }
        
        return count;
    }
};