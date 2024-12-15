class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        int n = classes.size();
        vector<double> ratios(n);

        for (int i = 0; i < n; i++) {
            ratios[i] = (double)classes[i][0] / classes[i][1];
        }

        priority_queue<pair<double, int>> pq;

        for (int i = 0; i < n; i++) {
            double currentRatio = ratios[i];
            double gain = (double)(classes[i][0] + 1) / (classes[i][1] + 1) - currentRatio;
            pq.push({gain, i});
        }

        while (extraStudents--) {
            auto top = pq.top();
            pq.pop();
            int idx = top.second;

            classes[idx][0]++;
            classes[idx][1]++;

            double currentRatio = (double)classes[idx][0] / classes[idx][1];
            double newGain = (double)(classes[idx][0] + 1) / (classes[idx][1] + 1) - currentRatio;
            pq.push({newGain, idx});
        }

        double totalRatio = 0.0;
        for (int i = 0; i < n; i++) {
            totalRatio += (double)classes[i][0] / classes[i][1];
        }

        return totalRatio / n;
    }
};