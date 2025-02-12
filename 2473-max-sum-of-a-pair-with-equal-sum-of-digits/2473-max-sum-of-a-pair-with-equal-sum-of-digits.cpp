class Solution {
public:
    int maximumSum(vector<int>& nums) {
        unordered_map<int, int> mp;
        int ans = -1;

        for(int n : nums) {
            int sum = 0, curr = n;
            while(curr > 0) {
                sum += curr % 10;
                curr = curr / 10;
            }

            if(mp.find(sum) != mp.end()) {
                ans = max(mp[sum] + n, ans);
                if(mp[sum] < n) mp[sum] = n;
            } else {
                mp[sum] = n;
            }
        }

        return ans;
    }
};