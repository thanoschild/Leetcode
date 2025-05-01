class Solution {
public:
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        int n = tasks.size(), m = workers.size();
        sort(tasks.begin(), tasks.end());
        sort(workers.begin(), workers.end());

        int lo = 0, hi = min(n, m);

        while (lo < hi) {
            int mid = (lo + hi + 1) / 2;
            multiset<int> ms(workers.end() - mid, workers.end()); // strongest mid workers
            int usedPills = 0;
            bool possible = true;

            for (int i = mid - 1; i >= 0; --i) {
                auto it = prev(ms.end());
                if (*it >= tasks[i]) {
                    ms.erase(it);
                } else {
                    auto usePill = ms.lower_bound(tasks[i] - strength);
                    if (usePill == ms.end()) {
                        possible = false;
                        break;
                    }
                    ms.erase(usePill);
                    usedPills++;
                    if (usedPills > pills) {
                        possible = false;
                        break;
                    }
                }
            }

            if (possible) lo = mid;
            else hi = mid - 1;
        }

        return lo;
    }
};