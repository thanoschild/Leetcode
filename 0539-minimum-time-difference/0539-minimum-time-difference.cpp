class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<bool> seen(24 * 60, false);
        int maxMin = INT_MIN, minMin = INT_MAX;
        
        for(const string& s : timePoints) {
            int h = stoi(s.substr(0, 2));
            int m = stoi(s.substr(3, 2));
            int totalMinutes = h * 60 + m;
            
            if(seen[totalMinutes]) return 0;
            
            maxMin = max(maxMin, totalMinutes);
            minMin = min(minMin, totalMinutes);
            seen[totalMinutes] = true;
        }

        int diff = INT_MAX, prev = 0;
        for(int i = minMin; i <= maxMin; ++i) {
            if(seen[i]) {
                if(i == minMin) {
                    diff = min(diff, min(maxMin - minMin, 1440 - maxMin + minMin));
                } else {
                    diff = min(diff, i - prev);
                }
                prev = i;
            }
        }

        return diff;
    }
};