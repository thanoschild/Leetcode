class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int mx = -1, mn = -1, diff = -1;
        for(int i = 0; i<arrays.size(); i++) {
            int currMax = arrays[i][arrays[i].size() - 1];
            int currMin = arrays[i][0];
            if(i == 0) {
                mx = currMax;
                mn = currMin;
            }
            else {
                diff = max(diff, currMax - mn);
                diff = max(diff, mx - currMin);
                mx = max(mx, currMax);
                mn = min(mn, currMin);
            }
        }

        return diff;
    }
};