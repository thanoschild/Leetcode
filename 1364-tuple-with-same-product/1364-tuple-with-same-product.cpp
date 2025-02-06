class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int, int> products;
        int ans = 0, n = nums.size();

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int prod = nums[i] * nums[j];
                ans += products[prod]++;
            }
        }
        return ans * 8;
    }
};