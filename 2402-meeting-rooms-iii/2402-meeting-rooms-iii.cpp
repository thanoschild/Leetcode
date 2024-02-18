class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meet) {
        vector<int> ans(n, 0);
        vector<long long> time(n, 0);
        sort(meet.begin(), meet.end());

        for(int i = 0; i<meet.size(); i++) {
            int start = meet[i][0], end = meet[i][1];
            long long minval = 1e18, idx = -1;
            bool flag = true;

            for(int j = 0; j<n; j++) {
                if(minval > time[j]) {
                    minval = time[j];
                    idx = j;
                }

                if(start >= time[j]) {
                    time[j] = end;
                    ans[j]++;
                    flag = false;
                    break;
                }
            }

            if(flag) {
                ans[idx]++;
                time[idx] += (end - start);
            }
        }

        int idx = -1, count = -1;
        for(int i = 0; i<n; i++) {
            if(ans[i] > count) {
                count = ans[i];
                idx = i;
            }
        }

        return idx;
    }
};