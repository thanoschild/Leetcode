class Solution {
public:
    int countDays(int days, vector<vector<int>>& meet) {
        sort(meet.begin(), meet.end());

        vector<vector<int>> arr;
        for(auto it : meet) {
            if(arr.size() == 0 || it[0] > arr.back()[1]) {
                arr.push_back(it);
            } else {
                arr.back()[1] = max(arr.back()[1], it[1]);
            }
        } 

        int meetDays = 0;
        for(auto it : arr) {
            meetDays += ((it[1] - it[0]) + 1);
        }

        return days - meetDays;
    }
};