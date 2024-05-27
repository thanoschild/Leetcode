class Solution {
public:
    int specialArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> count(n+1, 0);

        for(int num : nums) {
            if(num >= n) count[n]++;
            else count[num]++;
        }

        int ans = 0;
        for(int i = n; i>0; i--) {
            ans += count[i];
            if(i == ans) return ans;
        }

        return -1;
    }
};