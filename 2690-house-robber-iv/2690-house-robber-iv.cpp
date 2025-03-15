class Solution {
public:
    bool isValid(vector<int> &nums, int mid, int k) {
        int count = 0;
        for(int i = 0; i<nums.size(); i++) {
            if(nums[i] <= mid) {
                count++;
                i++;
            }
        }
        return count >= k;
    }

    int minCapability(vector<int>& nums, int k) {
        int left = 1, right = *max_element(nums.begin(), nums.end()), ans = 0;

        while(left <= right) {
            int mid = (right - left)/2 + left;
            if(isValid(nums, mid, k)) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return ans;
    }
};