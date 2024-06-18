class Solution {
public:
    static bool myCompare(pair<int,int> &a, pair<int,int> &b) {
        if(a.first == b.first) return a.second > b.second;
        return a.first < b.first;
    }

    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n = profit.size();
        vector<pair<int,int>> jobs;
        for(int i = 0; i<n; i++) {
            jobs.push_back({difficulty[i], profit[i]});
        }
        sort(jobs.begin(), jobs.end(), myCompare);
        sort(worker.begin(), worker.end());

        int ans = 0, idx = 0, curr = 0, m = worker.size();
        for(int i = 0; i<m; i++) {
            while(idx < n && jobs[idx].first <= worker[i]) {
                curr = max(curr, jobs[idx].second);
                idx++;
            }
            ans += curr;
        }

        return ans;
    }
};