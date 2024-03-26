class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        vector<bool> seen(n + 1, 0);

        for(auto it : nums) {
            if(it >= 0 && it <= n) {
                seen[it] = true;
            }
        }

        for(int i = 1; i<=n; i++) {
            if(!seen[i]) return i;
        }

        return n + 1;
    }
};