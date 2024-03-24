class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[0];
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
        while(fast != slow);

        fast = nums[0];
        while(fast != slow) {
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;

        // for(int i = 0; i<nums.size(); i++) {
        //     int idx = abs(nums[i]) - 1;
        //     nums[idx] *= -1;
        //     if(nums[idx] > 0) return abs(nums[i]);
        // }

        // return -1;
    }
};