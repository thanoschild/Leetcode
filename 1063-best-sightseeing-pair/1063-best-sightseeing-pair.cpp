class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int ans = INT_MIN;
        int curr = values[0];

        for(int i = 1; i<values.size(); i++) {
            ans = max(ans, curr + values[i] - i);
            curr = max(curr, values[i] + i);
        }

        return ans;
    }
};