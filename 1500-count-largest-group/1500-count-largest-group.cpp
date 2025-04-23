class Solution {
public:
    int countLargestGroup(int n) {
        int maxSize = 0, ans = 0;
        unordered_map<int,int>mp;

        for(int i = 1; i<=n; i++) {
            int currSum = 0, val = i;
            while(val > 0) {
                currSum += (val % 10);
                val /= 10;
            }
            mp[currSum]++;
            maxSize = max(maxSize, mp[currSum]);
        }

        for(auto it : mp) {
            if(it.second == maxSize) ans++;
        }

        return ans;
    }
};