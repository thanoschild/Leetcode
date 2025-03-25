class Solution {
public:
    bool checkPartition(vector<pair<int,int>> intervals) {
        sort(intervals.begin(), intervals.end());
    
        int end = intervals[0].second, sections = 0;
        for(auto it : intervals) {
            if(it.first >= end) sections++;
            end = max(end, it.second);
        }

        return sections >= 2;
    }

    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        vector<pair<int,int>> yaxis;
        vector<pair<int,int>> xaxis;
        for(auto it : rectangles) {
            xaxis.push_back({it[0], it[2]});
            yaxis.push_back({it[1], it[3]});
        }

        return checkPartition(xaxis) || checkPartition(yaxis);
    }
};