class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int ans = 0, n = points.size();
        for(int i = 1; i<n; i++) {
            vector<int> curr = points[i];
            vector<int> prev = points[i-1];
            ans += max(abs(curr[0] - prev[0]), abs(curr[1] - prev[1]));
        }
        return ans;
    }
};