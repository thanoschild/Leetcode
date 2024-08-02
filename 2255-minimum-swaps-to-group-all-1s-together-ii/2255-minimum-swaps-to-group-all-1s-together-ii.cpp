class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size(), ones = 0, zeros = 0;
        for(int i = 0; i<n; i++) {
            if(nums[i] == 1) ones++;
        }

        for(int i = 0; i<ones; i++) {
            if(nums[i] == 0) zeros++;
        }

        int minSwaps = zeros;
        for (int i = 1; i < n; i++) {
            int start = i;
            int end = (i + ones - 1) % n;

            if (nums[start - 1] == 0) {
                zeros--;
            }
            if (nums[end] == 0) {
                zeros++;
            }

            minSwaps = min(minSwaps, zeros);
        }

        return minSwaps;
    }
};