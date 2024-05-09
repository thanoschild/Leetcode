class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.begin(), happiness.end(), greater<int>());
        long long ans = 0;
      
        for(int i = 0; i<k; i++) {
            happiness[i] = max(0, happiness[i] - i);
            ans += happiness[i];
        }

        return ans;
    }
};