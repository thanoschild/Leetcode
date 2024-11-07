class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int ans = 0, curr = 0;
        for(int i = 1; i<=10000000; i <<= 1) {
            curr = 0;
            for(int n : candidates) {
                if((n & i) > 0) curr++;
            }
            ans = max(ans, curr);
        }

        return ans;
    }
};