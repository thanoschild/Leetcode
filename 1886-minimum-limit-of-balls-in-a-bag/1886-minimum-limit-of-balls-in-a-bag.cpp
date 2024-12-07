class Solution {
public:
    bool check(vector<int> &nums, int maxBalls, int maxOperations) {
        int count = 0;
        for(auto n : nums) {
            count += (n + maxBalls - 1) / maxBalls - 1;
            if(count > maxOperations) return false;
        }
        return true;
    }

    int minimumSize(vector<int>& nums, int maxOperations) {
        int left = 1, right = *max_element(nums.begin(), nums.end());
        int ans = right;

        while(left < right) {
            int mid = (right - left)/2 + left;
            if(check(nums, mid, maxOperations)) {
                right = mid;
                ans = right;
            } else {
                left = mid + 1;
            }
        }

        return ans;
    }
};