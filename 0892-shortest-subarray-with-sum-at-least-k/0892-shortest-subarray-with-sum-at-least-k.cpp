class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size(), ans = INT_MAX;
        long long sum = 0;
        deque<pair<long long, int>> pq;

        for(int i = 0; i<n; i++) {
            sum += nums[i];

            if(sum >= k) ans = min(ans, i + 1);

            while(!pq.empty() && sum - pq.front().first >= k) {
                auto[x, y] = pq.front();
                pq.pop_front();
                ans = min(ans, i - y);
            }

            while(!pq.empty() && pq.back().first > sum) {
                pq.pop_back();
            }

            pq.push_back({sum, i});
        }

        return ans == INT_MAX ? -1 : ans;
    }
};