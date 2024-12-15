class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        int n = classes.size();
        vector<double> ratios(n);

        // Initial ratio calculation
        for (int i = 0; i < n; i++) {
            ratios[i] = (double)classes[i][0] / classes[i][1];
        }

        // Max heap or priority queue to maximize the gain in ratio
        priority_queue<pair<double, int>> pq;

        // Initialize priority queue with the gain of each class
        for (int i = 0; i < n; i++) {
            double currentRatio = ratios[i];
            double gain = (double)(classes[i][0] + 1) / (classes[i][1] + 1) - currentRatio;
            pq.push({gain, i});
        }

        // Distribute the extra students
        while (extraStudents--) {
            auto top = pq.top();
            pq.pop();
            int idx = top.second;

            // Update class data
            classes[idx][0]++;
            classes[idx][1]++;

            // Recalculate gain for this class and push back into the priority queue
            double currentRatio = (double)classes[idx][0] / classes[idx][1];
            double newGain = (double)(classes[idx][0] + 1) / (classes[idx][1] + 1) - currentRatio;
            pq.push({newGain, idx});
        }

        // Calculate the final average ratio
        double totalRatio = 0.0;
        for (int i = 0; i < n; i++) {
            totalRatio += (double)classes[i][0] / classes[i][1];
        }

        return totalRatio / n;
    }
};