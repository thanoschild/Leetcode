class Solution {
public:
    static bool myCompare(vector<int> &a, vector<int> &b) {
        if(a[1] == b[1]) return a[0] < b[0];
        return a[1] < b[1];
    }

    int jobScheduling(vector<int>& start, vector<int>& end, vector<int>& pro) {
        int n = start.size();
        vector<vector<int>> jobs;
        for(int i = 0; i<n; i++) {
            jobs.push_back({start[i], end[i], pro[i]});
        }

        sort(jobs.begin(), jobs.end(), myCompare);
        map<int, int> mp;
        mp[0] = 0;

        for(auto it : jobs) {
            int curr = prev(mp.upper_bound(it[0]))->second + it[2];
            if(curr > mp.rbegin()->second) {
                mp[it[1]] = curr;
            }
        }

        return mp.rbegin()->second;
    }
};