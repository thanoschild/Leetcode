class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int idx = 0;

        for(int i = 1; i<intervals.size(); i++) {
            if(intervals[idx][1] >=  intervals[i][0]) {
               intervals[idx][0] = min(intervals[idx][0], intervals[i][0]);
               intervals[idx][1] = max(intervals[idx][1], intervals[i][1]);
            }
            else {
                idx++;
                intervals[idx][0] = intervals[i][0];
                intervals[idx][1] = intervals[i][1];
            }
        }

        intervals.resize(idx + 1);
        return intervals;
    }
};